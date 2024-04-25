#pragma once

#include "sfml_basis.h"

namespace ge {
    class SceneChangesSfmlBasic : public ge::SfmlBasis {
        ~SceneChangesSfmlBasic() override = default;
        void draw(sf::RenderWindow &window) override {} /// TODO: реализовать
    };
}