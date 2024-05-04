#include "scene_sfml_basis.h"

void ge::SceneSfmlBasis::draw(sf::RenderWindow &window) {
    window.draw(background_sprite_);

    for (const sf::Sprite &slots_spite: slots_spites_) {
        window.draw(slots_spite);
    }

    window.draw(replica_background_);
    window.draw(speaker_background_);
    window.draw(speaker_);
    window.draw(replica_);

    for (const sf::Text &action_button: action_buttons_) {
        window.draw(action_button);
    }
}
