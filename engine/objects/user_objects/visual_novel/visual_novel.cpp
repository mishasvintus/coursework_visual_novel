#include "visual_novel.h"
#include "non_user_objects/window_manager/window_manager.h"

#include <memory>
#include <utility>
#include <iostream>

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
          sound_track_(visual_novel.sound_track_),
          icon_(visual_novel.icon_),
          saves_dir_() {
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

void ge::VisualNovel::setInfo(const std::wstring &info) {
    info_ = info;
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

void ge::VisualNovel::setSoundTrack(const std::string &sound_track) {
    sound_track_ = sound_track;
}

void ge::VisualNovel::setIcon(const std::string &icon) {
    icon_ = icon;
}

void ge::VisualNovel::setSavesDir(const std::string &saves_dir) {
    saves_dir_ = saves_dir;
}

void ge::VisualNovel::setSoundVolume(float sound_volume) {
    music_.setVolume(sound_volume);
}

const std::wstring &ge::VisualNovel::getAboutAuthors() const {
    return about_authors_;
}

const ge::Frame &ge::VisualNovel::getEndingFrame() const {
    return ending_frame_;
}

const ge::Script &ge::VisualNovel::getScript() const {
    return script_;
}

const std::string &ge::VisualNovel::getNameStartChapter() const {
    return name_start_chapter_;
}

const std::string &ge::VisualNovel::getMainMenuBackground() const {
    return main_menu_background_;
}

const std::string &ge::VisualNovel::getSettingsBackground() const {
    return settings_background_;
}

const std::string &ge::VisualNovel::getAboutAuthorsBackground() const {
    return about_authors_background_;
}

const std::string &ge::VisualNovel::getSoundTrack() const {
    return sound_track_;
}

const std::string &ge::VisualNovel::getIcon() const {
    return icon_;
}

const std::string &ge::VisualNovel::getSavesDir() const {
    return saves_dir_;
}

bool ge::VisualNovel::run() {
    try {
        sf::RenderWindow window(sf::VideoMode::getDesktopMode(), project_name_, sf::Style::Fullscreen,
                                sf::ContextSettings(0, 0, 2));
        sf::Image icon;
        icon.loadFromFile(icon_);
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

        if (!music_.openFromFile(sound_track_)) {
            std::cerr << "Can't open sound_track " << sound_track_;
        }

        music_.setLoop(true);
        music_.setVolume(
                static_cast<float>(drawable_elements.getSettingsPtr()->getParameterValues()[drawable_elements.getSettingsPtr()->SOUND_VOLUME_INDEX]));
        music_.play();

        while (window.isOpen()) {
            if (!window_managers[current_game_mode_](*this, window, drawable_elements)) {
                std::cerr << "Something went wrong while managing window" << std::endl;
                break;
            }
            window.display();
        }
    } catch (...) {
        return false;
    }
    return true;
}