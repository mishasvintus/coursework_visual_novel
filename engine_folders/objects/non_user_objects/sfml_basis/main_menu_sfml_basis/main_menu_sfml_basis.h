#pragma once

#include "sfml_basis.h"

namespace ge {
    class MainMenuSfmlBasis: SfmlBasis {
    public:
        MainMenuSfmlBasis() = default;

        explicit MainMenuSfmlBasis(const size_t quantity_of_buttons);

        void draw(sf::RenderWindow &window) override;

        sf::RectangleShape title_background_;
        sf::Text title_;
        std::vector<sf::Text> buttons_;
    };
}
