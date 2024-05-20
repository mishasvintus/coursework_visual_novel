#include "settings_sfml_basis.h"

void ge::SettingsSfmlBasis::draw(sf::RenderWindow &window) {
    window.draw(background_sprite);
    window.draw(parameters_background);
    window.draw(title);
    for (sf::Text &parameter: parameters) {
        window.draw(parameter);
    }
    for (std::vector<sf::Text> &arrow_switch: arrow_switches) {
        window.draw(arrow_switch[0]);
        window.draw(arrow_switch[1]);
        window.draw(arrow_switch[2]);
    }
    window.draw(back_button_background);
    window.draw(back_button);
}