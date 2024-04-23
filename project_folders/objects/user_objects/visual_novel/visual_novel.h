#pragma once

#include "scene.h"
#include "script.h"

#include <string>

namespace ge {
    enum GameMode {
        MainMenu,
        MainSettings,
        AboutAuthors,
        Ingame,
        RecentScript,
        Info,
        IngameMenu,
        IngameSettings,
    };

    class VisualNovel {
    public:
        VisualNovel() = default;

        VisualNovel(const VisualNovel &visual_novel) = default;

        VisualNovel(VisualNovel &visual_novel) = default;

        VisualNovel(VisualNovel &&visual_novel) noexcept;

        VisualNovel(std::string about_authors, Script script);

        ~VisualNovel() = default;

        bool setAboutAuthors(const std::string &about_authors);

        bool setScript(const Script &script);

        const std::string &getAboutAuthors();

        const Script &getScript();

        bool run();

    private:
        static constexpr size_t UPPER_BOUND_LENGTH_ABOUT_AUTHORS = 5000;
        std::string about_authors_;
        Script script_;
        std::string current_chapter_;
        unsigned int current_scene_ = -1;
        GameMode current_game_mode_ = Ingame;

        bool windowManage(GameMode current_game_mode_, const std::string& current_chapter, unsigned int current_scene);
    };
}
