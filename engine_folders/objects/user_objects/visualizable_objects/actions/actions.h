#pragma once

#include "visualizable.h"

#include <SFML/System/Vector2.hpp>

namespace ge {
    class Action : Visualizable {
    public:
        Action();

        Action(const sf::Vector2i &coords, std::string text, std::string chapter_name_to_go);

        Action(const Action &action);

        Action(Action &action);

        Action(Action &&action) noexcept;

        ~Action() override = default;

        Action &operator=(const Action &action);

        Action &operator=(Action &&action) noexcept;

        [[nodiscard]] const sf::Vector2u &getCoords() const;

        [[nodiscard]] const std::string &getText() const;

        [[nodiscard]] const std::string &getChapterNameToGo() const;

        void setCoords(const sf::Vector2u &coords);

        void setText(const std::string &text);

        void setChapterNameToGo(const std::string &chapter_name_to_go);

    private:
        bool renderSfmlBasis(const sf::Vector2u &window_size) override {
            return true; /// TODO: реализовать
        }

        void clearSfmlBasis() override {
            /// TODO: реализовать
        }

        std::shared_ptr<SfmlBasis> getSfmlBasis() override {
            return {}; /// TODO: реализовать
        }

        const sf::Vector2u COORDS_LOW_LIMIT = {0, 0};
        const sf::Vector2u COORDS_HIGH_LIMIT = {10000, 10000};
        /// TODO: не константа, потому что sf::VideoMode нестатичен, переделать как-то

        sf::Vector2u coords_;
        std::string text_;
        std::string chapter_name_to_go_;
    };
}
