#pragma once

#include "non_user_objects/visualizable_objects/visualizable.h"
#include "main_menu_sfml_basis.h"

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

        void setTitle(const std::wstring &title);

        [[nodiscard]] unsigned int getSelectedButton() const;

        void setBackground(const std::string &background);

        const std::string &getBackground();

        void moveUp();

        void moveDown();

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        std::wstring title_ = L"ФИДЕС";
        unsigned int selected_button_ = 0;
        bool is_rendered_ = false;
        std::shared_ptr<MainMenuSfmlBasis> sfml_basis_ = nullptr;
        std::string background_;

        static constexpr unsigned int TOP_BUTTON_INDEX = 0;
        static constexpr unsigned int BOTTOM_BUTTON_INDEX = 4;
        static constexpr unsigned int QUANTITY_OF_BUTTONS = 5;
        static constexpr unsigned int UPPER_BOUND_TITLE_LENGTH = 40;
        const std::vector<std::wstring> BUTTONS = {
                L"НОВАЯ ИГРА", L"ЗАГРУЗИТЬ ИГРУ", L"НАСТРОЙКИ", L"ОБ АВТОРАХ", L"ВЫХОД"
        };
    };
}
