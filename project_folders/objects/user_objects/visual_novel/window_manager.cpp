#include "window_manager.h"

std::unordered_map<ge::GameMode, WindowManagerPtr> ge::WindowManager::getMap() {
    std::unordered_map<ge::GameMode, WindowManagerPtr> result;

    result[MainMenu] = &ge::WindowManager::mainMenuManager;
    result[MainSettings] = &ge::WindowManager::mainSettingsManager;
    result[AboutAuthors] = &ge::WindowManager::aboutAuthorsManager;
    result[InGame] = &ge::WindowManager::inGameManager;
    result[RecentScript] = &ge::WindowManager::recentScriptManager;
    result[Info] = &ge::WindowManager::infoManager;
    result[IngameMenu] = &ge::WindowManager::ingameMenuManager;
    result[IngameSettings] = &ge::WindowManager::ingameSettingsManager;

    return result;
}