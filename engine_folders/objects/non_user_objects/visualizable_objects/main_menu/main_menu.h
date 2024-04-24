#pragma once

#include "visualizable.h"
#include "main_menu_sfml_basis/main_menu_sfml_basis.h"

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

        void setTitle(const std::string &title);

        void MoveUp();

        void MoveDown();

    private:

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        static constexpr unsigned int TOP_BUTTON_INDEX = 0;
        static constexpr unsigned int BOTTOM_BUTTON_INDEX = 4;
        static constexpr unsigned int QUANTITY_OF_BUTTONS = 5;
        static constexpr unsigned int UPPER_BOUND_TITLE_LENGTH = 40;

        const std::vector<std::string> BUTTONS = {"НОВАЯ ИГРА", "ЗАГРУЗИТЬ ИГРУ", "НАСТРОЙКИ", "ОБ АВТОРАХ", "ВЫХОД"};
        std::string title_ = "ФИДЕС";
        unsigned int selected_button_ = 0;
        bool is_rendered_ = false;
        std::shared_ptr<MainMenuSfmlBasis> sfml_basis_ = nullptr;
    };
}
