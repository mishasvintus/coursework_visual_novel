#pragma once

#include "sfml_basis.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace ge {
    class Visualizable {
    public:
        virtual ~Visualizable() = default;

        const std::string FONT_NAME = "engine_folders/data/comic_sans.ttf";
    private:
        std::vector<std::shared_ptr<sf::Drawable>> drawables_;

        virtual bool renderSfmlBasis(const sf::Vector2u &window_size) = 0;

        virtual void clearSfmlBasis() = 0;

        virtual std::shared_ptr<SfmlBasis> getSfmlBasis() = 0;
    };
}
