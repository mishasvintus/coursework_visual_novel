#include "window_manager.h"
#include <thread>
#include <chrono>

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
    while (window.pollEvent(event)) {
        switch (mainMenuEventHandler(window, drawable_elements.putMainMenu(), event)) {
            case GameMode::MainMenu: {
                break;
            }
            case GameMode::InGame: {
                Frame &initial_frame = visual_novel.script_.chapters_[visual_novel.getNameStartChapter()].frames_[0];
                std::shared_ptr<Scene> scene(
                        new Scene(std::make_shared<Frame>(initial_frame),
                                  visual_novel.getNameStartChapter(),
                                  0));

                drawable_elements.setScene(scene);
                drawable_elements.resetMainMenu();
                visual_novel.current_game_mode_ = GameMode::InGame;
                return true;
            }
            case GameMode::MainSettings:
                // TODO : реализовать
                break;
            case GameMode::AboutAuthors:
                // TODO : реализовать
                break;
            default:
                return false;
        }
    }

    window.clear();
    std::shared_ptr<MainMenu> main_menu = drawable_elements.getMainMenuPtr();
    main_menu->renderSfmlBasis(window.getSize());
    std::shared_ptr<SfmlBasis> sfml_basis = main_menu->getSfmlBasis();
    sfml_basis->draw(window);
    std::this_thread::sleep_for(std::chrono::milliseconds(8));
    return true;
}

ge::GameMode inGameEventHandler(sf::RenderWindow &window, ge::Scene &scene, sf::Event event) {
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
                scene.moveUp();
                break;
            }
            if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
                scene.moveDown();
                break;
            }
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
                scene.moveLeft();
                break;
            }
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
                scene.moveRight();
                break;
            }
            if (event.key.code == sf::Keyboard::Escape) {
                return ge::GameMode::MainMenu;
            }
            if (event.key.code != sf::Keyboard::Enter) {
                break;
            }

            break;
        default:
            break;
    }
    return ge::GameMode::InGame;
}

bool ge::WindowManager::inGameManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                      ge::DrawableElements &drawable_elements) {
    if (!drawable_elements.getScenePtr()) {
        return false;
    }
    sf::Event event{};
    while (window.pollEvent(event)) {
        switch (inGameEventHandler(window, drawable_elements.putScene(), event)) {
            case GameMode::InGame: {
                break;
            }
            case GameMode::MainMenu: {
                window.clear();
                std::shared_ptr<MainMenu> main_menu(new MainMenu);
                main_menu->renderSfmlBasis(window.getSize());
                std::shared_ptr<SfmlBasis> sfml_basis = main_menu->getSfmlBasis();
                drawable_elements.resetScene();
                drawable_elements.setMainMenu(main_menu);
                sfml_basis->draw(window);
                visual_novel.current_game_mode_ = GameMode::MainMenu;
                return true;
            }
            default:
                return false;
        }
    }
    window.clear();
    std::shared_ptr<Scene> scene = drawable_elements.getScenePtr();
    scene->setNewFrame(std::make_shared<Frame>(
            visual_novel.script_.chapters_[scene->current_chapter_name_].frames_[scene->current_frame_number_]));
    scene->renderSfmlBasis(window.getSize());
    std::shared_ptr<SfmlBasis> sfml_basis = scene->getSfmlBasis();
    sfml_basis->draw(window);
    std::this_thread::sleep_for(std::chrono::milliseconds(8));
    return true;
}
