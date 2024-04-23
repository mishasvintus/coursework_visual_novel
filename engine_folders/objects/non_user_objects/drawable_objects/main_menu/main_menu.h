#pragma once

#include "drawable.h"


namespace ge {
    class MainMenu : Drawable {
    public:
        MainMenu() = default;

        MainMenu(const MainMenu &main_menu);

        MainMenu(MainMenu &main_menu);

        MainMenu(MainMenu &&main_menu) noexcept;

        ~MainMenu() override = default;

        MainMenu& operator=(const MainMenu& main_menu);

        MainMenu& operator=(MainMenu&& main_menu) noexcept ;

        void MoveUp();

        void MoveDown();

    private:
        std::vector<sf::Sprite> getSpriteVector(const sf::Vector2u &window_size) override {
            return {}; ///TODO: реализовать
        }

        static constexpr unsigned int UP = 0;
        static constexpr unsigned int QUANTITY_OF_BUTTONS_ = 5;

        unsigned int selected_button_ = 0;
    };
}
