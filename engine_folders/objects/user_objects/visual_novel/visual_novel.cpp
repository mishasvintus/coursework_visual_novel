#include "visual_novel.h"
#include "non_user_objects/window_manager/window_manager.h"

#include <utility>

void checkingCorrectness(const std::string &text, const size_t upper_limit_about_authors,
                         const std::string &project_name, const size_t upper_limit_project_name) {
    if (text.length() > upper_limit_about_authors || project_name.length() > upper_limit_project_name) {
        throw std::invalid_argument("length of text about authors is so long\n");
    }
}

ge::VisualNovel::VisualNovel(VisualNovel &&visual_novel) noexcept
    : about_authors_(std::move(visual_novel.about_authors_)), script_(std::move(visual_novel.script_)) {
}

ge::VisualNovel::VisualNovel(std::string about_authors, Script script, std::string project_name)
    : about_authors_(std::move(about_authors)), script_(std::move(script)), project_name_(std::move(project_name)) {
    checkingCorrectness(about_authors_, UPPER_BOUND_LENGTH_ABOUT_AUTHORS, project_name_,
                        UPPER_BOUND_LENGTH_PROJECT_NAME);
}

void ge::VisualNovel::setAboutAuthors(const std::string &about_authors) {
    checkingCorrectness(about_authors, UPPER_BOUND_LENGTH_ABOUT_AUTHORS, project_name_,
                        UPPER_BOUND_LENGTH_PROJECT_NAME);
    about_authors_ = about_authors;
}

void ge::VisualNovel::setScript(const Script &script) {
    script_ = script;
}

void ge::VisualNovel::setProjectName(const std::string &project_name) {
    checkingCorrectness(about_authors_, UPPER_BOUND_LENGTH_ABOUT_AUTHORS, project_name,
                        UPPER_BOUND_LENGTH_ABOUT_AUTHORS);
    project_name_ = project_name;
}


const std::string &ge::VisualNovel::getAboutAuthors() {
    return about_authors_;
}

const ge::Script &ge::VisualNovel::getScript() {
    return script_;
}

bool ge::VisualNovel::run() {
    try {
        sf::RenderWindow window(sf::VideoMode::getDesktopMode(), project_name_, sf::Style::Fullscreen);
        window.setVerticalSyncEnabled(true);
        std::unordered_map<GameMode, WindowManagerPtr> window_managers = ge::WindowManager::getMap();

        std::shared_ptr<MainMenu> main_menu(new MainMenu);
        ge::DrawableElements drawable_elements;
        drawable_elements.setMainMenu(main_menu);
        while (window.isOpen()) {
            window_managers[current_game_mode_](*this, window, drawable_elements);
            window.display();
        }
    } catch (...) {
        return false;
    }
    return true;
}
