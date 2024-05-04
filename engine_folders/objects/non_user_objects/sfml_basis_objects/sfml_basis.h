#pragma once

#include <SFML/Graphics.hpp>
namespace ge {
    class SfmlBasis {
    public:
        virtual ~SfmlBasis() = default;
        virtual void draw(sf::RenderWindow &window) = 0;
    };
}