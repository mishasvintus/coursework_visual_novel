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

ge::GameMode mainMenuEventHandler(sf::RenderWindow &window, ge::MainMenu &main_menu, sf::Event event) {
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyReleased: {
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
                main_menu.moveUp();
                break;
            }
            if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
                main_menu.moveDown();
                break;
            }
            if (event.key.code != sf::Keyboard::Enter) {
                break;
            }
            const unsigned int selected_button = main_menu.getSelectedButton();
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

bool ge::WindowManager::mainMenuManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                        ge::DrawableElements &drawable_elements) {
    sf::Event event{};
    window.waitEvent(event);
    switch (mainMenuEventHandler(window, drawable_elements.putMainMenu(), event)) {
        case GameMode::MainMenu: {
            window.clear();
            std::shared_ptr<MainMenu> main_menu = drawable_elements.getMainMenuPtr();
            main_menu->renderSfmlBasis(window.getSize());
            std::shared_ptr<SfmlBasis> sfml_basis = main_menu->getSfmlBasis();
            sfml_basis->draw(window);
            break;
        }
        case GameMode::InGame:
            drawable_elements.setScene(std::make_shared<Scene>());
            drawable_elements.resetMainMenu();
            // TODO reset mainmenu
            visual_novel.current_game_mode_ = GameMode::InGame;
            break;
        case GameMode::MainSettings:
            // TODO : реализовать
            break;
        case GameMode::AboutAuthors:
            // TODO : реализовать
            break;
        default:
            return false;
    }
    return true;
}

bool ge::WindowManager::inGameManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                      ge::DrawableElements &drawable_elements) {
    sf::Event event{};
    window.waitEvent(event);
    switch (mainMenuEventHandler(window, drawable_elements.putMainMenu(), event)) {
        case GameMode::InGame: {
            window.clear();
            std::shared_ptr<Scene> scene = drawable_elements.getScenePtr();
            scene->setNewFrame(std::make_shared<Frame>(
                    visual_novel.script_.chapters_[scene->current_chapter_name_].frames_[scene->current_frame_number_]));
            scene->renderSfmlBasis(window.getSize());
            std::shared_ptr<SfmlBasis> sfml_basis = scene->getSfmlBasis();
            sfml_basis->draw(window);
            break;
        }
        default:
            return false;
    }
    return true;
}
