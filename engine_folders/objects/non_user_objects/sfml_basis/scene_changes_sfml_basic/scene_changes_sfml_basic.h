#pragma once

#include "sfml_basis.h"

namespace ge {
    class SceneChangesSfmlBasic : public ge::SfmlBasis {
    public:
        SceneChangesSfmlBasic() = default;

        ~SceneChangesSfmlBasic() override = default;

        void draw(sf::RenderWindow &window) override;

        sf::Texture background_texture_;
        sf::Sprite background_sprite_;
        sf::Font replica_font_;
        sf::Font speaker_font_;
        sf::Font action_font_;
        sf::Text replica_;
        sf::Text speaker_;
        sf::RectangleShape replica_background_;
        sf::RectangleShape speaker_background_;
        std::vector<sf::Texture> slots_textures_;
        std::vector<sf::Sprite> slots_spites_;
        std::vector<sf::Text> action_buttons_;
        sf::Vector2u window_size_;
    };
}
