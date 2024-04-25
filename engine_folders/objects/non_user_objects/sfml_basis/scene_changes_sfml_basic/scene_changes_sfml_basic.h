#pragma once

#include "sfml_basis.h"

namespace ge {
    class SceneChangesSfmlBasic : public ge::SfmlBasis {
    public:
        SceneChangesSfmlBasic() = default;

        ~SceneChangesSfmlBasic() override = default;

        void draw(sf::RenderWindow &window) override;

        sf::Font replica_font_;
        sf::Font speaker_font_;
        sf::Text replica_;
        sf::Text speaker_;
        sf::RectangleShape dialogue_box_shape;
        sf::Sprite background_sprite_;
        std::vector<sf::Sprite> slots_spites_;
        std::vector<sf::Text> buttons_;
    };
}
