#include "main_menu_sfml_basis.h"

ge::MainMenuSfmlBasis::MainMenuSfmlBasis(size_t quantity_of_buttons) {
    buttons_.resize(quantity_of_buttons);
}

void ge::MainMenuSfmlBasis::draw(sf::RenderWindow &window) {
    window.draw(background_sprite_);
    window.draw(title_background_);
    window.draw(title_);
    for (const sf::Text &button: buttons_) {
        window.draw(button);
    }
}