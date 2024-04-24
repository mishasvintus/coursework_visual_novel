#pragma once

#include "visualizable.h"


namespace ge {
    class MainMenuSfmlBasis {
    public:
        MainMenuSfmlBasis() = default;

        explicit MainMenuSfmlBasis(size_t quantity_of_buttons) {
            buttons.resize(quantity_of_buttons);
        }

        sf::RectangleShape title_background;
        sf::Text title;
        std::vector<sf::Text> buttons;

        void draw(sf::RenderWindow &window) {
            window.draw(title_background);
            window.draw(title);
            for (const sf::Text &button: buttons) {
                window.draw(button);
            }
        }
    };

    class MainMenu : Visualizable {
    public:
        MainMenu() = default;

        MainMenu(const MainMenu &main_menu);

        MainMenu(MainMenu &main_menu);

        MainMenu(MainMenu &&main_menu) noexcept;

        ~MainMenu() override = default;

        MainMenu &operator=(const MainMenu &main_menu);

        MainMenu &operator=(MainMenu &&main_menu) noexcept;

        void setTitle(const std::string &title);

        void MoveUp();

        void MoveDown();

    private:
        std::shared_ptr<MainMenuSfmlBasis> sfml_basis_ = nullptr;

        bool is_rendered_ = false;

        bool renderSfmlBasis(const sf::Vector2u &window_size); //override

        void clearSfmlBasis(); //override

        std::shared_ptr<MainMenuSfmlBasis>
        getSfmlBasis(); //override //вообще должен возвращать родительский класс SfmlBasis, для полиморфизма, чтоб потом ко всем draw применить

        static constexpr unsigned int TOP_BUTTON_INDEX = 0;
        static constexpr unsigned int BOTTOM_BUTTON_INDEX = 4;
        static constexpr unsigned int QUANTITY_OF_BUTTONS = 5;
        static constexpr unsigned int UPPER_BOUND_TITLE_LENGTH = 40;
        const std::vector<std::string> BUTTONS = {"НОВАЯ ИГРА", "ЗАГРУЗИТЬ ИГРУ", "НАСТРОЙКИ", "ОБ АВТОРАХ", "ВЫХОД"};
        std::string title_ = "ФИДЕС";
        unsigned int selected_button_ = 0;
    };
}
