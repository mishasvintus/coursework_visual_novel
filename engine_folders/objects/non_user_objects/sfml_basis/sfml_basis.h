#pragma once

#include <SFML/Graphics.hpp>

class SfmlBasis {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};