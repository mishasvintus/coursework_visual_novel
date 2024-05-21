#pragma once

#include "non_user_objects/visualizable_objects/sfml_basis.h"

namespace ge {
    class IngameMenuSfmlBasis : public SfmlBasis {
    public:
        ~IngameMenuSfmlBasis() override = default;

        void draw(sf::RenderWindow &window) override;

        sf::Sprite background_sprite;
        sf::Font font;
        sf::Text title;
        sf::RectangleShape window_shape;
        std::vector<sf::Text> buttons;
        sf::Text back_button;
        sf::RectangleShape back_button_background;
    };
}