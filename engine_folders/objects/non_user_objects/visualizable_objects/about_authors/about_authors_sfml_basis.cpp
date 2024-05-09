#include "about_authors_sfml_basis.h"

void ge::AboutAuthorsSfmlBasis::draw(sf::RenderWindow &window) {
    window.draw(background_sprite);
    window.draw(text_);
    window.draw(back_button_);
}