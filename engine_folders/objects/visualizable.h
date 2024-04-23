#pragma once

#include <SFML/Graphics.hpp>

namespace ge {
    class Visualizable {
    public:
        virtual ~Visualizable() = default;
        static constexpr std::string FONT_NAME = "comic_sans.ttf";
    private:
        virtual std::vector<sf::Drawable> getDrawableVector(const sf::Vector2u& window_size) = 0;
    };
}
