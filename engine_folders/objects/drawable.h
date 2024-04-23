#pragma once

#include <SFML/Graphics.hpp>

namespace ge {
    class Drawable {
    public:
        virtual ~Drawable() = default;

    private:
        virtual std::vector<sf::Sprite> getSpriteVector(const sf::Vector2u& window_size) = 0;
    };
}
