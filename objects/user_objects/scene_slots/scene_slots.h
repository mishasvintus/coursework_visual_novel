#pragma once

#include "object.h"

namespace ge {
    class SceneSlots : Object {
    public:

    private:
        std::vector<sf::Sprite> getSpriteVector(const sf::Vector2i& window_size) override;
    };
}