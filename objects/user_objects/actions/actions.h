#pragma once

#include <SFML/System/Vector2.hpp>
#include "object.h"
#include "chapter.h"

namespace ge {

    class Action: Object {
        Action();
        Action(const Action& action);
        Action(Action& action);
        Action(Action&& action);
        ~Action() = default;

    private:
        sf::Vector2i coords_;
        std::string text_;
        Chapter chapter_to_go_;
    };
}

