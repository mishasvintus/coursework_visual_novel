#pragma once

#include <SFML/Graphics.hpp>

namespace ge {
    class Object {
    public:
        virtual ~Object() = default;

    private:
        virtual std::vector<sf::Sprite> getSpriteVector(const sf::Vector2i& window_size) = 0;
    };
}