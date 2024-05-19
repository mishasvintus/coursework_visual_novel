#pragma once

#include "non_user_objects/visualizable_objects/sfml_basis.h"

namespace ge {
    class IngameSettingsSfmlBasis : public SfmlBasis {
    public:
        ~IngameSettingsSfmlBasis() override = default;

        void draw(sf::RenderWindow &window) override;

        sf::Texture background_texture;
        sf::Sprite background_sprite;
        sf::Font font;
        sf::Text title;
        sf::RectangleShape parameters_background;
        std::vector<sf::Text> parameters;
        std::vector<std::vector<sf::Text> > arrow_switches;
        sf::Text back_button;
        sf::RectangleShape back_button_background;
    };
}