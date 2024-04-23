#pragma once

#include "visual_novel/visual_novel.h"

using WindowManagerPtr = bool (*)(ge::VisualNovel &, sf::RenderWindow &);

namespace ge {
    class WindowManager {
    public:
        static bool mainMenuManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window) {}

        static bool mainSettingsManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window){}

        static bool aboutAuthorsManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window){}

        static bool inGameManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window){}

        static bool recentScriptManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window){}

        static bool infoManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window){}

        static bool ingameMenuManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window){}

        static bool ingameSettingsManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window){}

        static std::unordered_map<GameMode, WindowManagerPtr> getMap();
    };
}