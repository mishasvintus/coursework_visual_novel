#pragma once

#include "sfml_basis.h"

namespace ge {
    class SceneChangesSfmlBasic : public ge::SfmlBasis {
    public:
        SceneChangesSfmlBasic() = default;

        ~SceneChangesSfmlBasic() override = default;

        void draw(sf::RenderWindow &window) override {
        } /// TODO: реализовать

        sf::Font replica_font_;
        sf::Font speaker_font_;
        sf::RectangleShape dialogue_box_shape;
        sf::Sprite background_sprite_;
        sf::Texture background_texture_;
        std::vector<sf::Sprite> slots_spites_;
        std::vector<sf::Texture> slots_textue_;
        sf::Text button_;
    };
}
