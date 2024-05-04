#pragma once

#include "sfml_basis.h"

namespace ge {
    class MainMenuSfmlBasis : public SfmlBasis {
    public:
        MainMenuSfmlBasis() = default;

        ~MainMenuSfmlBasis() override = default;

        explicit MainMenuSfmlBasis(size_t quantity_of_buttons);

        void draw(sf::RenderWindow &window) override;

        sf::Font font_;
        sf::Sprite background_sprite_;
        sf::Texture background_texture_;
        sf::RectangleShape title_background_;
        sf::Text title_;
        std::vector<sf::Text> buttons_;
    };
}
