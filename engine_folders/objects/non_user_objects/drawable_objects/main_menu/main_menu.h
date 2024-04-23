#pragma once

#include "drawable.h"


namespace ge {
    class MainMenu : Drawable {
        MainMenu();
        MainMenu(const MainMenu &main_menu);
        MainMenu(MainMenu &main_menu);
        MainMenu(MainMenu &&main_menu);
        ~MainMenu() = default;

        void MoveUp();
        void MoveDown();
    private:
        unsigned int selected_button;
        std::vector<sf::Sprite> getSpriteVector(const sf::Vector2u& window_size) override;
        const unsigned int QUANTITY_OF_BUTTONS_ = 5;

    };
}
