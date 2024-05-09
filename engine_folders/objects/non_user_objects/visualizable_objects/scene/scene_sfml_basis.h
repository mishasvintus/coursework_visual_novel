#pragma once

#include "non_user_objects/visualizable_objects/sfml_basis.h"

namespace ge {
    class SceneSfmlBasis : public ge::SfmlBasis {
    public:
        SceneSfmlBasis() = default;

        ~SceneSfmlBasis() override = default;

        void draw(sf::RenderWindow &window) override;

        sf::Texture background_texture;
        sf::Sprite background_sprite;

        sf::Font font;

        std::vector<sf::Texture> slots_textures;
        std::vector<sf::Sprite> slots_sprites;

        sf::Text replica;
        sf::Text speaker;
        sf::RectangleShape replica_background;
        sf::RectangleShape speaker_background;
        std::vector<sf::Text> action_buttons;

        sf::RectangleShape next_background;
        sf::Text next;

        std::vector<sf::CircleShape> button_backgrounds;
        std::vector<sf::Text> button_symbols;
        sf::Vector2u window_size;
    };
}
