#include "visual_novel.h"

#include <utility>

void checkingCorrectness(const std::string &text, const size_t upper_limit) {
    if (text.length() > upper_limit) {
        throw std::invalid_argument("length of text about authors is so long\n");
    }
}

ge::VisualNovel::VisualNovel(VisualNovel &&visual_novel) noexcept
        : about_authors_(std::move(visual_novel.about_authors_)), script_(std::move(visual_novel.script_)) {
}

ge::VisualNovel::VisualNovel(std::string about_authors, Script script)
        : about_authors_(std::move(about_authors)), script_(std::move(script)) {
    checkingCorrectness(about_authors_, UPPER_BOUND_LENGTH_ABOUT_AUTHORS);
}

bool ge::VisualNovel::setAboutAuthors(const std::string &about_authors) {
    try {
        checkingCorrectness(about_authors, UPPER_BOUND_LENGTH_ABOUT_AUTHORS);
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
    sf::RenderWindow window(sf::VideoMode(1, 3), "visual_novel", sf::Style::Fullscreen);

    while (window.isOpen()) {
        windowManage(current_game_mode_, current_chapter_, current_scene_);
    }
    return true;
}


