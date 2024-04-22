#pragma once

#include <SFML/System/Vector2.hpp>
#include "object.h"

namespace ge {
    class Chapter;

    class Action : Object {
    public:
        Action();

        Action(const Action &action);

        Action(Action &action);

        Action(Action &&action);

        ~Action() = default;

    private:
        sf::Vector2i coords_;
        std::string text_;
        std::string chapter_name_to_go_;

        std::vector<sf::Sprite> getSpriteVector(const sf::Vector2i& window_size) override;
    };
}

