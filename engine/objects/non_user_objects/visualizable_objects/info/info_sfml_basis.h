#pragma once

#include "non_user_objects/visualizable_objects/sfml_basis.h"

namespace ge {
    class InfoSfmlBasis : public ge::SfmlBasis {
    public:
        InfoSfmlBasis() = default;

        ~InfoSfmlBasis() override = default;

        void draw(sf::RenderWindow &window) override;

        sf::Texture background_texture;
        sf::Sprite background_sprite;
        sf::Font font;
        sf::Text title;
        sf::Text text;
        sf::RectangleShape text_background;
        sf::Text back_button;
        sf::RectangleShape back_button_background;
    };
}