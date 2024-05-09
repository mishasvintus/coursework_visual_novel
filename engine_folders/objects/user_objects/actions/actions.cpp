#include "actions.h"

#include <utility>

void checkingCorrectness(const sf::Vector2f &relative_coords, const sf::Vector2f &low_limits,
                         const sf::Vector2f &high_limits) {
    if (relative_coords.x < low_limits.x || relative_coords.y < low_limits.y || relative_coords.x > high_limits.x ||
        relative_coords.y > high_limits.y) {
        throw std::invalid_argument("the transmitted coordinates are off-screen\n");
    }
    //TODO: добавить проверку на корректность длин текстов
}

ge::Action::Action() {
    checkingCorrectness(relative_coords_, COORDS_LOW_LIMIT, COORDS_HIGH_LIMIT);
}

ge::Action::Action(const Action &action)
        : relative_coords_(action.relative_coords_), text_(action.text_),
          chapter_name_to_go_(action.chapter_name_to_go_) {
    checkingCorrectness(relative_coords_, COORDS_LOW_LIMIT, COORDS_HIGH_LIMIT);
}

ge::Action::Action(const sf::Vector2f &coords, std::wstring text, std::wstring chapter_name_to_go)
        : relative_coords_(coords), text_(std::move(text)), chapter_name_to_go_(std::move(chapter_name_to_go)) {
    checkingCorrectness(relative_coords_, COORDS_LOW_LIMIT, COORDS_HIGH_LIMIT);
}

ge::Action::Action(Action &action)
        : relative_coords_(action.relative_coords_), text_(action.text_),
          chapter_name_to_go_(action.chapter_name_to_go_) {
}

ge::Action::Action(Action &&action) noexcept
        : relative_coords_(action.relative_coords_), text_(std::move(action.text_)),
          chapter_name_to_go_(std::move(action.chapter_name_to_go_)) {
}

ge::Action &ge::Action::operator=(const Action &action) {
    relative_coords_ = action.relative_coords_;
    text_ = action.text_;
    chapter_name_to_go_ = action.chapter_name_to_go_;
    return *this;
}

ge::Action &ge::Action::operator=(Action &&action) noexcept {
    std::swap(relative_coords_, action.relative_coords_);
    text_ = std::move(action.text_);
    chapter_name_to_go_ = std::move(action.chapter_name_to_go_);
    return *this;
}

bool ge::Action::operator==(const Action &action) const {
    return (relative_coords_ == action.getCoords()) && (text_ == action.getText()) &&
           (chapter_name_to_go_ == action.chapter_name_to_go_);
}

const sf::Vector2f &ge::Action::getCoords() const {
    return relative_coords_;
}

const std::wstring &ge::Action::getText() const {
    return text_;
}

const std::wstring &ge::Action::getChapterNameToGo() const {
    return chapter_name_to_go_;
}

void ge::Action::setRelativeCoords(const sf::Vector2f &relative_coords) {
    checkingCorrectness(relative_coords, COORDS_LOW_LIMIT, COORDS_HIGH_LIMIT);
    relative_coords_ = relative_coords;
}

void ge::Action::setText(const std::wstring &text) {
    /// TODO: проверка текста
    text_ = text;
}

void ge::Action::setChapterNameToGo(const std::wstring &chapter_name_to_go) {
    /// TODO: проверка текста
    chapter_name_to_go_ = chapter_name_to_go;
}
