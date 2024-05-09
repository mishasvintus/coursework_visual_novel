#pragma once

#include "visual_novel/visual_novel.h"
#include "elements_to_draw.h"

using WindowManagerPtr = bool (*)(ge::VisualNovel &, sf::RenderWindow &, ge::DrawableElements &);

namespace ge {
    class WindowManager {
    public:
        static bool mainMenuManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                    ge::DrawableElements &drawable_elements);

        static bool mainSettingsManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                        ge::DrawableElements &drawable_elements) {
            // TODO
            return true;
        }

        static bool aboutAuthorsManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                        ge::DrawableElements &drawable_elements);

        static bool inGameManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                  ge::DrawableElements &drawable_elements);

        static bool recentScriptManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                        ge::DrawableElements &drawable_elements) {
            // TODO
            return true;
        }

        static bool infoManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                ge::DrawableElements &drawable_elements) {
            // TODO
            return true;
        }

        static bool ingameMenuManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                      ge::DrawableElements &drawable_elements) {
            // TODO
            return true;
        }

        static bool ingameSettingsManager(ge::VisualNovel &visual_novel, sf::RenderWindow &window,
                                          ge::DrawableElements &drawable_elements) {
            // TODO
            return true;
        }

        static std::unordered_map<GameMode, WindowManagerPtr> getMap();
    };
}
