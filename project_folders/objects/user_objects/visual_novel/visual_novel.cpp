#include "visual_novel.h"

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

bool ge::VisualNovel::setAboutAuthors(const std::string &about_authors) {
    try {
        checkingCorrectness(about_authors, UPPER_BOUND_LENGTH_ABOUT_AUTHORS, project_name_,
                            UPPER_BOUND_LENGTH_PROJECT_NAME);
        about_authors_ = about_authors;
    } catch (...) {
        return false;
    }
    return true;
}

bool ge::VisualNovel::setScript(const Script &script) {
    try {
        script_ = script;
    } catch (...) {
        return false;
    }
    return true;
}


const std::string &ge::VisualNovel::getAboutAuthors() {
    return about_authors_;
}

const ge::Script &ge::VisualNovel::getScript() {
    return script_;
}

bool ge::VisualNovel::run() {
    try {
        sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "visual_novel", sf::Style::Fullscreen);
        window.setVerticalSyncEnabled(true);
        while (window.isOpen()) {
            sf::Event event{};
            if (window.waitEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear();
            window.display();
        }
    } catch (...) {
        return false;
    }
    return true;
}
