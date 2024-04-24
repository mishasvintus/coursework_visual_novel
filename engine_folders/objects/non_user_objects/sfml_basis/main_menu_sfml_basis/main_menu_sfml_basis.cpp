#include "main_menu_sfml_basis.h"

ge::MainMenuSfmlBasis::MainMenuSfmlBasis(size_t quantity_of_buttons) {
    buttons.resize(quantity_of_buttons);
}

void ge::MainMenuSfmlBasis::draw(sf::RenderWindow &window) {
    window.draw(title_background);
    window.draw(title);
    for (const sf::Text &button: buttons) {
        window.draw(button);
    }
}