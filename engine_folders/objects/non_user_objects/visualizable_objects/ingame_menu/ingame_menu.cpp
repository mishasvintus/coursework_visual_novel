#include "ingame_menu.h"

ge::IngameMenu::IngameMenu(const ge::IngameMenu &ingame_menu)
    : is_rendered_(ingame_menu.is_rendered_)
    , background_(ingame_menu.background_)
    , sfml_basis_(ingame_menu.sfml_basis_)
    , selected_row_(ingame_menu.selected_row_) {
}

ge::IngameMenu::IngameMenu(ge::IngameMenu &ingame_menu)
    : is_rendered_(ingame_menu.is_rendered_)
    , background_(ingame_menu.background_)
    , sfml_basis_(ingame_menu.sfml_basis_)
    , selected_row_(ingame_menu.selected_row_) {
}

ge::IngameMenu::IngameMenu(ge::IngameMenu &&ingame_menu) noexcept
    : is_rendered_(ingame_menu.is_rendered_)
    , background_(std::move(ingame_menu.background_))
    , sfml_basis_(std::move(ingame_menu.sfml_basis_))
    , selected_row_(ingame_menu.selected_row_) {
}

ge::IngameMenu &ge::IngameMenu::operator=(const ge::IngameMenu &ingame_menu) {
    is_rendered_ = ingame_menu.is_rendered_;
    background_ = ingame_menu.background_;
    sfml_basis_ = ingame_menu.sfml_basis_;
    selected_row_ = ingame_menu.selected_row_;
    return *this;
}

ge::IngameMenu &ge::IngameMenu::operator=(ge::IngameMenu &&ingame_menu) noexcept {
    is_rendered_ = ingame_menu.is_rendered_;
    background_ = std::move(ingame_menu.background_);
    sfml_basis_ = std::move(ingame_menu.sfml_basis_);
    selected_row_ = ingame_menu.selected_row_;
    return *this;
}

bool ge::IngameMenu::renderSfmlBasis(const sf::Vector2u &window_size) {
    //TODO
    return true;
}

void ge::IngameMenu::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::IngameMenu::getSfmlBasis() {
    return std::static_pointer_cast<ge::SfmlBasis>(sfml_basis_);
}