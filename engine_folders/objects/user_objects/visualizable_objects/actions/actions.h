#pragma once

#include "visualizable.h"

#include <SFML/System/Vector2.hpp>

namespace ge {
    class Action : Visualizable {
    public:
        Action();

        Action(const sf::Vector2i &coords, std::wstring text, std::wstring chapter_name_to_go);

        Action(const Action &action);

        Action(Action &action);

        Action(Action &&action) noexcept;

        ~Action() override = default;

        Action &operator=(const Action &action);

        Action &operator=(Action &&action) noexcept;

        bool operator==(const Action &action) const;

        [[nodiscard]] const sf::Vector2f &getCoords() const;

        [[nodiscard]] const std::wstring &getText() const;

        [[nodiscard]] const std::wstring &getChapterNameToGo() const;

        void setRelativeCoords(const sf::Vector2f &relative_coords);

        void setText(const std::wstring &text);

        void setChapterNameToGo(const std::wstring &chapter_name_to_go);

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

        const sf::Vector2f COORDS_LOW_LIMIT = {0, 0};
        const sf::Vector2f COORDS_HIGH_LIMIT = {1.0, 1.0};

        sf::Vector2f relative_coords_;
        std::wstring text_;
        std::wstring chapter_name_to_go_;
    };
}
