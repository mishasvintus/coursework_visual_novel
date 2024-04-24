#include "window_manager.h"

std::unordered_map<ge::GameMode, WindowManagerPtr> ge::WindowManager::getMap() {
    std::unordered_map<ge::GameMode, WindowManagerPtr> result;

    result[GameMode::MainMenu] = &ge::WindowManager::mainMenuManager;
    result[GameMode::MainSettings] = &ge::WindowManager::mainSettingsManager;
    result[GameMode::AboutAuthors] = &ge::WindowManager::aboutAuthorsManager;
    result[GameMode::InGame] = &ge::WindowManager::inGameManager;
    result[GameMode::RecentScript] = &ge::WindowManager::recentScriptManager;
    result[GameMode::Info] = &ge::WindowManager::infoManager;
    result[GameMode::IngameMenu] = &ge::WindowManager::ingameMenuManager;
    result[GameMode::IngameSettings] = &ge::WindowManager::ingameSettingsManager;

    return result;
}

ge::GameMode mainMenuEventHandler(sf::RenderWindow& window, ge::MainMenu& main_menu, sf::Event event) {
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
                main_menu.MoveUp();
                break;
            }
            if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
                main_menu.MoveDown();
                break;
            }
            if (event.key.code == sf::Keyboard::Enter) {
                unsigned int selected_button = main_menu.getSelectedButton();
                if (selected_button == 0) {
                    return ge::GameMode::InGame;
                }
                if (selected_button == 2) {
                    return ge::GameMode::MainSettings;
                }
                if (selected_button == 3) {
                    return ge::GameMode::AboutAuthors;
                }
                if (selected_button == 4) {
                    window.close();
                    break;
                }
                break;
            }
        default:
            break;
    }
    return ge::GameMode::MainMenu;
}
