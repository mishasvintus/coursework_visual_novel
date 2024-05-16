#include "ingame_menu_sfml_basis.h"

void ge::IngameMenuSfmlBasis::draw(sf::RenderWindow &window) {
    window.draw(background_sprite);
    window.draw(window_shape);
    window.draw(title);
    for (sf::Text& button : buttons) {
        window.draw(button);
    }
    window.draw(back_button_background);
    window.draw(back_button);
}