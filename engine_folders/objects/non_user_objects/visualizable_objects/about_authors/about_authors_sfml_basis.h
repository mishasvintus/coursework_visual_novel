#pragma once

#include "non_user_objects/visualizable_objects/sfml_basis.h"

namespace ge {
    class AboutAuthorsSfmlBasis : public ge::SfmlBasis {
    public:
        AboutAuthorsSfmlBasis() = default;

        ~AboutAuthorsSfmlBasis() override = default;

        void draw(sf::RenderWindow &window) override;

        sf::Texture background_texture;
        sf::Sprite background_sprite;
        sf::Font font_;
        sf::Text text_;
        sf::Text back_button_;
        sf::CircleShape back_button_background_;
    };
}