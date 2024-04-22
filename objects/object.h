#pragma once

#include <SFML/Graphics.hpp>

class Object {
public:
    virtual ~Object() = default;
private:
    virtual std::vector<sf::Sprite> getSpriteVector() = 0;
};
