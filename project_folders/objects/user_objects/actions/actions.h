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

        const sf::Vector2u &getCoords();

        const std::string &getText();

        const std::string &getChapterNameToGo();

        bool setCoords(const sf::Vector2u &coords);

        bool setText(const std::string &text);

        bool setChapterNameToGo(const std::string &chapter_name_to_go);

    private:
        std::vector<sf::Sprite> getSpriteVector(const sf::Vector2u &window_size) override {
            /// TODO: REALISE
            return {};
        }

        const sf::Vector2u COORS_LOW_LIMIT = {0, 0};
        const sf::Vector2u COORS_HIGH_LIMIT = {10000, 10000};
        /// TODO: не константа, потому что sf::VideoMode нестатичен, переделать как-то

        sf::Vector2u coords_;
        std::string text_;
        std::string chapter_name_to_go_;
    };
}
