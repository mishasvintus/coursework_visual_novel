#include "scene_sfml_basis.h"

void ge::SceneSfmlBasis::draw(sf::RenderWindow &window) {
    window.draw(background_sprite);

    for (const sf::Sprite &slots_spite: slots_sprites) {
        window.draw(slots_spite);
    }

    window.draw(replica_background);
    window.draw(speaker_background);
    window.draw(replica);
    window.draw(speaker);

    for (const sf::Text &action_button: action_buttons) {
        window.draw(action_button);
    }
    for (const sf::CircleShape &bottom_button_background: button_backgrounds) {
        window.draw(bottom_button_background);
    }
    for (const sf::Text &bottom_button_symbol: button_symbols) {
        window.draw(bottom_button_symbol);
    }
}
