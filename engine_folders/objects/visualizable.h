#pragma once

#include <SFML/Graphics.hpp>

namespace ge {
    class Visualizable {
    public:
        virtual ~Visualizable() = default;

        static constexpr std::string FONT_NAME = "comic_sans.ttf";
    private:
        std::vector<sf::Drawable> drawables_;

        virtual bool render(const sf::Vector2u &window_size) = 0;

        virtual void clearDrawables() = 0;

        virtual std::vector<sf::Drawable> getDrawables() = 0;
    };
}
