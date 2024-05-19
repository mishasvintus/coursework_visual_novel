#include "visual_novel.h"
#include "non_user_objects/window_manager/window_manager.h"

#include <memory>
#include <utility>
#include <iostream>
#include <thread>
#include <SFML/Audio/Music.hpp>

void checkingCorrectness(const std::wstring &text, const size_t upper_limit_about_authors,
                         const std::wstring &project_name, const size_t upper_limit_project_name) {
    if (text.length() > upper_limit_about_authors || project_name.length() > upper_limit_project_name) {
        throw std::invalid_argument("length of text about authors is so long\n");
    }
}

ge::VisualNovel::VisualNovel(VisualNovel &&visual_novel) noexcept
        : about_authors_(std::move(visual_novel.about_authors_)), script_(std::move(visual_novel.script_)),
          project_name_(std::move(visual_novel.project_name_)),
          name_start_chapter_(std::move(visual_novel.name_start_chapter_)),
          current_frame_number_(visual_novel.current_frame_number_),
          music_files_(visual_novel.music_files_) {
    sound_volume_ = visual_novel.sound_volume_.load();
}

ge::VisualNovel::VisualNovel(std::wstring about_authors, Script script, std::wstring project_name,
                             std::string name_start_chapter)
        : about_authors_(std::move(about_authors)),
          script_(std::move(script)),
          project_name_(std::move(project_name)),
          name_start_chapter_(std::move(name_start_chapter)) {
    checkingCorrectness(about_authors_, UPPER_BOUND_LENGTH_ABOUT_AUTHORS, project_name_,
                        UPPER_BOUND_LENGTH_PROJECT_NAME);
}

void ge::VisualNovel::setAboutAuthors(const std::wstring &about_authors) {
    checkingCorrectness(about_authors, UPPER_BOUND_LENGTH_ABOUT_AUTHORS, project_name_,
                        UPPER_BOUND_LENGTH_PROJECT_NAME);
    about_authors_ = about_authors;
}

void ge::VisualNovel::setScript(const Script &script) {
    script_ = script;
}

void ge::VisualNovel::setProjectName(const std::wstring &project_name) {
    checkingCorrectness(about_authors_, UPPER_BOUND_LENGTH_ABOUT_AUTHORS, project_name,
                        UPPER_BOUND_LENGTH_ABOUT_AUTHORS);
    project_name_ = project_name;
}

void ge::VisualNovel::setEndingFrame(const Frame &ending_frame) {
    ending_frame_ = ending_frame;
}

void ge::VisualNovel::setNameStartChapter(const std::string &name_start_chapter) {
    name_start_chapter_ = name_start_chapter;
}

void ge::VisualNovel::setMainMenuBackground(const std::string &main_menu_background) {
    main_menu_background_ = main_menu_background;
}

void ge::VisualNovel::setSettingsBackground(const std::string &settings_background) {
    settings_background_ = settings_background;
}

void ge::VisualNovel::setAboutAuthorsBackground(const std::string &about_authors_background) {
    about_authors_background_ = about_authors_background;
}

void ge::VisualNovel::setMusicFiles(const std::vector<std::string> &music_files) {
    music_files_ = music_files;
}

void ge::VisualNovel::setSoundVolume(unsigned int sound_volume) {
    sound_volume_ = sound_volume;
}

const std::wstring &ge::VisualNovel::getAboutAuthors() {
    return about_authors_;
}

const ge::Frame &ge::VisualNovel::getEndingFrame() {
    return ending_frame_;
}

const ge::Script &ge::VisualNovel::getScript() {
    return script_;
}

const std::string &ge::VisualNovel::getNameStartChapter() {
    return name_start_chapter_;
}

const std::string &ge::VisualNovel::getMainMenuBackground() {
    return main_menu_background_;
}

const std::string &ge::VisualNovel::getSettingsBackground() {
    return settings_background_;
}

const std::string &ge::VisualNovel::getAboutAuthorsBackground() {
    return about_authors_background_;
}

const std::vector<std::string> &ge::VisualNovel::getMusicFiles() {
    return music_files_;
}

const std::atomic<unsigned int> &ge::VisualNovel::getSoundVolume() {
    return sound_volume_;
}

//
void ge::VisualNovel::playMusic(std::vector<std::string> &music_files, std::atomic<bool> &running, std::atomic<unsigned int> &sound_volume) {
    size_t current_song_index = 0;
    sf::Music music;

    if (music_files.empty()) {
        return;
    }

    while (running) {
        if (music.getStatus() == sf::Music::Stopped) {
            if (!music.openFromFile(music_files[current_song_index])) {
                std::cerr << "Could not load music file " << music_files[current_song_index] << std::endl;
                return;
            }
            music.play();
            current_song_index = (current_song_index + 1) % music_files.size();
        }
        music.setVolume(sound_volume);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

bool ge::VisualNovel::run() {
    try {
        sf::RenderWindow window(sf::VideoMode::getDesktopMode(), project_name_, sf::Style::Fullscreen,
                                sf::ContextSettings(0, 0, 2));
        sf::Image icon;
        icon.loadFromFile("engine_folders/data/images/icon128.png");
        window.setIcon(128, 128, icon.getPixelsPtr());
        window.setFramerateLimit(60);
        window.setMouseCursorVisible(false);
        std::unordered_map<GameMode, WindowManagerPtr> window_managers = ge::WindowManager::getMap();

        ge::DrawableElements drawable_elements;
        drawable_elements.setMainMenu(std::make_shared<MainMenu>());
        drawable_elements.getMainMenuPtr()->setBackground(main_menu_background_);
        drawable_elements.getMainMenuPtr()->setTitle(project_name_);

        drawable_elements.setSettings(std::make_shared<Settings>());
        drawable_elements.getSettingsPtr()->setBackground(settings_background_);

        drawable_elements.setAboutAuthors(std::make_shared<AboutAuthors>());
        drawable_elements.getAboutAuthorsPtr()->setBackground(about_authors_background_);
        drawable_elements.getAboutAuthorsPtr()->setText(about_authors_);

        std::thread musicThread(playMusic, std::ref(music_files_), std::ref(is_running_), std::ref(sound_volume_));

        is_running_ = true;

        while (window.isOpen()) {
            if (!window_managers[current_game_mode_](*this, window, drawable_elements)) {
                std::cerr << "Something went wrong while managing window" << std::endl;
                break;
            }
            window.display();
        }
        is_running_ = false;
        musicThread.join();
    } catch (...) {
        is_running_ = false;
        return false;
    }
    return true;
}