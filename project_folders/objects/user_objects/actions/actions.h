#pragma once

#include "object.h"

#include <SFML/System/Vector2.hpp>

namespace ge {
    class Action : Object {
    public:
        Action();

        Action(const sf::Vector2i &coors, std::string text, std::string chapter_name_to_go);

        Action(const Action &action);

        Action(Action &action);

        Action(Action &&action) noexcept;

        ~Action() override = default;

        Action &operator=(const Action &action);

        Action &operator=(Action &&action) noexcept;

    private:
        std::vector<sf::Sprite> getSpriteVector(const sf::Vector2u &window_size) override {
            //TODO: REALISE
            return {};
        }

        const sf::Vector2u COORS_LOW_LIMIT = {0, 0};
        const sf::Vector2u COORS_HIGH_LIMIT = {10000, 10000};
                    //TODO: не константа, потому что sf::VideoMode нестатичен, переделать как-то

        sf::Vector2u coors_;
        std::string text_; //// возможно лучше string_view
        std::string chapter_name_to_go_; //// возможно лучше string_view
    };
}
