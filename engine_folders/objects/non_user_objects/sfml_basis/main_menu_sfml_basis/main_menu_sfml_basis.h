#pragma once

#include "sfml_basis.h"

namespace ge {
    class MainMenuSfmlBasis : SfmlBasis {
    public:
        MainMenuSfmlBasis() = default;

        explicit MainMenuSfmlBasis(size_t quantity_of_buttons);

        sf::RectangleShape title_background;
        sf::Text title;
        std::vector<sf::Text> buttons;

        void draw(sf::RenderWindow &window) override;
    };
}