#include "scene_changes_sfml_basic.h"

void ge::SceneChangesSfmlBasic::draw(sf::RenderWindow &window) {
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
