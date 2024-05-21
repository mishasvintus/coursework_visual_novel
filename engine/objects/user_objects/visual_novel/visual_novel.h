#pragma once

#include "game_mode.h"
#include "frame.h"
#include "script.h"
#include "cache_manager.h"

#include <SFML/Audio/Music.hpp>

namespace ge {

    class VisualNovel {
    public:
        VisualNovel() = default;

        VisualNovel(const VisualNovel &visual_novel) = default;

        VisualNovel(VisualNovel &visual_novel) = default;

        VisualNovel(VisualNovel &&visual_novel) noexcept;

        VisualNovel(std::wstring about_authors, Script script, std::wstring project_name,
                    std::string name_start_chapter);

        ~VisualNovel() = default;

        void setAboutAuthors(const std::wstring &about_authors);

        void setInfo(const std::wstring &info);

        void setScript(const Script &script);

        void setProjectName(const std::wstring &project_name);

        void setEndingFrame(const Frame &ending_frame);

        void setNameStartChapter(const std::string &name_start_chapter);

        void setMainMenuBackground(const std::string &main_menu_background);

        void setSettingsBackground(const std::string &settings_background);

        void setAboutAuthorsBackground(const std::string &about_authors_background);

        void setSoundTrack(const std::string &sound_track);

        void setSoundVolume(float sound_volume);

        void setIcon(const std::string &icon);

        void setSavesDir(const std::string &saves_dir);

        const std::wstring &getAboutAuthors() const;

        const Script &getScript() const;

        const std::string &getNameStartChapter() const;

        const Frame &getEndingFrame() const;

        const std::string &getMainMenuBackground() const;

        const std::string &getSettingsBackground() const;

        const std::string &getAboutAuthorsBackground() const;

        const std::string &getSoundTrack() const;

        const std::string &getIcon() const;

        const std::string &getSavesDir() const;

        bool loadChapterCache(const std::string &chapter_name, size_t from_frame, size_t to_frame);

        void resetCache(bool delete_service_images);

        bool run();

    private:
        friend class WindowManager;

        static constexpr size_t UPPER_BOUND_LENGTH_ABOUT_AUTHORS = 5000;
        static constexpr size_t UPPER_BOUND_LENGTH_PROJECT_NAME = 50;
        std::wstring about_authors_;
        std::wstring info_;
        Script script_;
        Frame ending_frame_;
        std::string main_menu_background_;
        std::string settings_background_;
        std::string about_authors_background_;
        std::string sound_track_;
        std::string icon_;
        std::string saves_dir_;
        std::shared_ptr<sf::Music> music_ = nullptr;
        std::wstring project_name_ = L"Visual Novel";
        GameMode current_game_mode_ = GameMode::MainMenu;
        std::shared_ptr<CacheManager> cache_manager_;
        std::string name_start_chapter_; //TODO: сделать проверку на наличие в мапе
        unsigned int current_frame_number_ = 0;
    };
}