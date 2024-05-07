#pragma once

#include "non_user_objects/visualizable_objects/sfml_basis.h"

namespace ge {
    class SceneSfmlBasis : public ge::SfmlBasis {
    public:
        SceneSfmlBasis() = default;

        ~SceneSfmlBasis() override = default;

        void draw(sf::RenderWindow &window) override;

        sf::Texture background_texture_;
        sf::Sprite background_sprite_;
        sf::Font font_;
        std::vector<sf::Texture> slots_textures_;
        std::vector<sf::Sprite> slots_spites_;
        sf::Text replica_;
        sf::Text speaker_;
        sf::RectangleShape replica_background_;
        sf::RectangleShape speaker_background_;
        std::vector<sf::Text> action_buttons_;
        sf::Vector2u window_size_;
    };
}
