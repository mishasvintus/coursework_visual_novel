#pragma once

#include "frame.h"
#include "script.h"

namespace ge {
    enum class GameMode {
        MainMenu,
        MainSettings,
        AboutAuthors,
        InGame,
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

        VisualNovel(std::wstring about_authors, Script script, std::wstring project_name,
                    std::wstring  name_start_chapter);

        ~VisualNovel() = default;

        void setAboutAuthors(const std::wstring &about_authors);

        void setScript(const Script &script);

        void setProjectName(const std::wstring &project_name);

        void setEndingFrame(const Frame &ending_frame);

        void setNameStartChapter(const std::wstring& name_start_chapter);

        void setMainMenuBackground(const std::string &main_menu_background);

        void setSettingsBackground(const std::string &settings_background);

        void setAboutAuthorsBackground(const std::string &about_authors_background);

        const std::wstring &getAboutAuthors();

        const Script &getScript();

        const std::wstring &getNameStartChapter();

        const Frame &getEndingFrame();

        const std::string &getMainMenuBackground();

        const std::string &getSettingsBackground();

        const std::string &getAboutAuthorsBackground();

        bool run();

    private:
        friend class WindowManager;

        static constexpr size_t UPPER_BOUND_LENGTH_ABOUT_AUTHORS = 5000;
        static constexpr size_t UPPER_BOUND_LENGTH_PROJECT_NAME = 50;
        std::wstring about_authors_;
        Script script_;
        Frame ending_frame_;
        std::string main_menu_background_;
        std::string settings_background_;
        std::string about_authors_background_;
        std::wstring project_name_ = L"Visual Novel";
        GameMode current_game_mode_ = GameMode::MainMenu;
        std::wstring name_start_chapter_; //TODO: сделать проверку на наличие в мапе
        unsigned int current_frame_number_ = 0;
    };
}