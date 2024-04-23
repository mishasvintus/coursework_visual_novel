#include "main_menu.h"

void checkingCorrectness(const unsigned int selected_button, const unsigned int upper_limit) {
    if (selected_button > upper_limit - 1) {
        throw std::invalid_argument("so big number in selected_button\n");
    }
}

ge::MainMenu::MainMenu(const MainMenu &main_menu)
        : selected_button_(main_menu.selected_button_) {
}

ge::MainMenu::MainMenu(MainMenu &main_menu)
        : selected_button_(main_menu.selected_button_) {
}

ge::MainMenu::MainMenu(MainMenu &&main_menu) noexcept
        : selected_button_(main_menu.selected_button_) {
}

ge::MainMenu &ge::MainMenu::operator=(const MainMenu &main_menu) {
    selected_button_ = main_menu.selected_button_;
    return *this;
}

ge::MainMenu &ge::MainMenu::operator=(MainMenu &&main_menu) noexcept {
    selected_button_ = main_menu.selected_button_;
    return *this;
}

void ge::MainMenu::MoveUp() {
    if (selected_button_ != TOP_BUTTON_INDEX_) {
        --selected_button_;
    }
}

void ge::MainMenu::MoveDown() {
    if (selected_button_ != BOTTOM_BUTTON_INDEX_) {
        --selected_button_;
    }
}

std::vector<sf::Drawable> getDrawableVector(const sf::Vector2u &window_size) {
    /// TODO
}