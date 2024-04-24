#pragma once

#include "visualizable.h"


namespace ge {
    class MainMenu : Visualizable {
    public:
        MainMenu() = default;

        MainMenu(const MainMenu &main_menu);

        MainMenu(MainMenu &main_menu);

        MainMenu(MainMenu &&main_menu) noexcept;

        ~MainMenu() override = default;

        MainMenu &operator=(const MainMenu &main_menu);

        MainMenu &operator=(MainMenu &&main_menu) noexcept;

        void MoveUp();

        void MoveDown();

    private:
        bool render(const sf::Vector2u &window_size) override {
            return true; /// TODO: реализовать
        }

        void clearDrawables() override {
            /// TODO: реализовать
        }

        std::vector<sf::Drawable> getDrawables() override;

        static constexpr unsigned int TOP_BUTTON_INDEX_ = 0;
        static constexpr unsigned int BOTTOM_BUTTON_INDEX_ = 4;
        static constexpr unsigned int QUANTITY_OF_BUTTONS_ = 5;
        const std::vector<std::string> BUTTONS_ = {"НОВАЯ ИГРА", "ЗАГРУЗИТЬ ИГРУ", "НАСТРОЙКИ", "ОБ АВТОРАХ", "ВЫХОД"};
        const std::string TITLE_ = "ФИДЕС";
        unsigned int selected_button_ = 0;
    };
}
