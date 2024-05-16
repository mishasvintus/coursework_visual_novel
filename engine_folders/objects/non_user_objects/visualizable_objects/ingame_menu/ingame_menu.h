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
        const unsigned int BUTTONS_QUANTITY = 1;
        const std::vector<std::wstring> BUTTONS = {L"ВЫЙТИ В ГЛАВНОЕ МЕНЮ"};
        const std::wstring BACK_BUTTON_TEXT = L"Назад";
    };
}
