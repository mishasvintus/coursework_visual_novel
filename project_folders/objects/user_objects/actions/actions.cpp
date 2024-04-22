#include "actions.h"

#include <utility>

void checkingCorrectness(const sf::Vector2u& coors, const sf::Vector2u& low_limits, const sf::Vector2u& high_limits) {
    if (coors.x < low_limits.x || coors.y < low_limits.y || coors.x > high_limits.x || coors.y > high_limits.y) {
        throw std::invalid_argument("the transmitted coordinates are off-screen\n");
    }
    //TODO: добавить проверку на корректность длин текстов
}

ge::Action::Action() {
    checkingCorrectness(coors_, COORS_LOW_LIMIT, COORS_HIGH_LIMIT);
}

ge::Action::Action(const Action &action)
    : coors_(action.coors_)
    , text_(action.text_)
    , chapter_name_to_go_(action.chapter_name_to_go_) {
    checkingCorrectness(coors_, COORS_LOW_LIMIT, COORS_HIGH_LIMIT);
}

ge::Action::Action(const sf::Vector2i& coors, std::string  text, std::string  chapter_name_to_go)
    : coors_(coors)
    , text_(std::move(text))
    , chapter_name_to_go_(std::move(chapter_name_to_go)) {
    checkingCorrectness(coors_, COORS_LOW_LIMIT, COORS_HIGH_LIMIT);
}

ge::Action::Action(Action &action)
    : coors_(action.coors_)
    , text_(action.text_)
    , chapter_name_to_go_(action.chapter_name_to_go_) {
}

ge::Action::Action(Action &&action) noexcept
    : coors_(action.coors_)
    , text_(std::move(action.text_))
    , chapter_name_to_go_(std::move(action.chapter_name_to_go_)) {
}

ge::Action &ge::Action::operator=(const Action &action) {
    coors_ = action.coors_;
    text_ = action.text_;
    chapter_name_to_go_ = action.chapter_name_to_go_;
    return *this;
}

ge::Action &ge::Action::operator=(Action &&action) noexcept {
    std::swap(coors_, action.coors_);
    text_ = std::move(action.text_);
    chapter_name_to_go_ = std::move(action.chapter_name_to_go_);
    return *this;
}
