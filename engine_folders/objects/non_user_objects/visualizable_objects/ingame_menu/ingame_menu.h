#pragma once

#include "non_user_objects/visualizable_objects/visualizable.h"
#include "ingame_menu_sfml_basis.h"

namespace ge {
    class IngameMenu : Visualizable {
    public:
        IngameMenu() = default;

        IngameMenu(const IngameMenu &ingame_menu);

        IngameMenu(IngameMenu &ingame_menu);

        IngameMenu(IngameMenu &&ingame_menu) noexcept;

        ~IngameMenu() override = default;

        IngameMenu &operator=(const IngameMenu &ingame_menu);

        IngameMenu &operator=(IngameMenu &&ingame_menu) noexcept;

        void setBackground(const std::string &background);

        void moveUp();

        void moveDown();

        [[nodiscard]] unsigned int getSelectedRow() const;

        const unsigned int CONTINUE_INDEX = 0;
        const unsigned int SAVES_INDEX = 1;
        const unsigned int SETTINGS_INDEX = 2;
        const unsigned int EXIT_INDEX = 3;

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        std::string background_;
        std::shared_ptr<IngameMenuSfmlBasis> sfml_basis_ = nullptr;

        unsigned int selected_row_ = 0;

        const std::wstring TITLE = L"МЕНЮ";
        const unsigned int BUTTONS_QUANTITY = 4;
        const unsigned int TOP_BUTTON_INDEX = 0;
        const unsigned int BOTTOM_BUTTON_INDEX = 3;
        const std::vector<std::wstring> BUTTONS = {L"ПРОДОЛЖИТЬ ИГРУ", L"СОХРАНИТЬ", L"НАСТРОЙКИ",
                                                   L"ВЫХОД"};
        const sf::Color ABROGATION = sf::Color(105, 105, 105);
        const sf::Color BACKGROUND_FILL_COLOR = sf::Color(66, 84, 127, 240);
    };
}
