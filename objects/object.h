#pragma once

#include <SFML/Graphics.hpp>

class Object {
public:
    virtual ~Object() = default;
private:
    virtual std::vector<sf::Sprite> getSpriteVector(sf::Vector2i window_size) = 0;
};