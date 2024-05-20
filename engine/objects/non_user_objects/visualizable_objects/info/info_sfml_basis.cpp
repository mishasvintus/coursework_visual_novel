#include "info_sfml_basis.h"

void ge::InfoSfmlBasis::draw(sf::RenderWindow &window) {
    window.draw(background_sprite);
    window.draw(text_background);
    window.draw(title);
    window.draw(text);
    window.draw(back_button_background);
    window.draw(back_button);
}