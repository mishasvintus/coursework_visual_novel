#include "recent_script_sfml_basis.h"

void ge::RecentScriptSfmlBasis::draw(sf::RenderWindow &window) {
    window.draw(background_sprite);
    window.draw(text_background);
    window.draw(title);
    for (std::pair<sf::Text, sf::Text>& pair : script_step) {
        window.draw(pair.first);
        window.draw(pair.second);
    }
    window.draw(back_button_background);
    window.draw(back_button);
}