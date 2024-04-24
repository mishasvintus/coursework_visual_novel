#include "main_menu.h"

void checkingCorrectness(const unsigned int selected_button, const unsigned int upper_limit_selected_button,
                         const std::string &title, const unsigned int upper_limit_title) {
    if (selected_button > upper_limit_selected_button - 1 || title.length() > upper_limit_title) {
        throw std::invalid_argument("so big number in selected_button\n");
    }
}

ge::MainMenu::MainMenu(const MainMenu &main_menu)
    : title_(main_menu.title_)
      , selected_button_(main_menu.selected_button_) {
}

ge::MainMenu::MainMenu(MainMenu &main_menu)
    : title_(main_menu.title_)
      , selected_button_(main_menu.selected_button_) {
}

ge::MainMenu::MainMenu(MainMenu &&main_menu) noexcept
    : title_(std::move(main_menu.title_))
      , selected_button_(main_menu.selected_button_) {
}

ge::MainMenu &ge::MainMenu::operator=(const MainMenu &main_menu) {
    selected_button_ = main_menu.selected_button_;
    title_ = main_menu.title_;
    return *this;
}

ge::MainMenu &ge::MainMenu::operator=(MainMenu &&main_menu) noexcept {
    selected_button_ = main_menu.selected_button_;
    title_ = std::move(main_menu.title_);
    return *this;
}

void ge::MainMenu::MoveUp() {
    if (selected_button_ != TOP_BUTTON_INDEX) {
        --selected_button_;
    }
}

void ge::MainMenu::MoveDown() {
    if (selected_button_ != BOTTOM_BUTTON_INDEX) {
        ++selected_button_;
    }
}

void ge::MainMenu::setTitle(const std::string &title) {
    checkingCorrectness(selected_button_, QUANTITY_OF_BUTTONS, title, UPPER_BOUND_TITLE_LENGTH);
    title_ = title;
}


std::vector<std::shared_ptr<sf::Drawable> > ge::MainMenu::getDrawables() {
    /// TODO

    return {};
}
