#pragma once

#include "about_authors.h"
#include "info.h"
#include "ingame_menu.h"
#include "ingame_settings.h"
#include "main_menu.h"
#include "recent_script.h"
#include "settings.h"

#include <memory>

namespace ge {
    class DrawableElements {
    public:
        DrawableElements() = default;

        DrawableElements(const DrawableElements &other) = default;

        DrawableElements(DrawableElements &other) = default;

        DrawableElements(DrawableElements &&other) noexcept;

        ~DrawableElements() = default;

        DrawableElements &operator=(const DrawableElements &other) = default;

        DrawableElements &operator=(DrawableElements &&other) noexcept;

        void SetAboutAuthors(const AboutAuthors &about_authors) const;

        std::shared_ptr<AboutAuthors> GetAboutAuthorsPtr();

        [[nodiscard]] const AboutAuthors &GetAboutAuthors() const;

        void SetInfo(const Info &info) const;

        std::shared_ptr<Info> GetInfoPtr();

        [[nodiscard]] const Info &GetInfo() const;

        void SetIngameMenu(const IngameMenu &ingame_menu) const;

        std::shared_ptr<IngameMenu> GetIngameMenuPtr();

        [[nodiscard]] const IngameMenu &GetIngameMenu() const;

        void SetIngameSettings(const IngameSettings &ingame_settings) const;

        std::shared_ptr<IngameSettings> GetIngameSettingsPtr();

        [[nodiscard]] const IngameMenu &GetIngameSettings() const;

        void SetMainMenu(const MainMenu &main_menu) const;

        std::shared_ptr<MainMenu> GetMainMenuPtr();

        [[nodiscard]] const MainMenu &GetMainMenu() const;

        void SetRecentScript(const RecentScript &recent_script) const;

        std::shared_ptr<RecentScript> GetRecentScriptPtr();

        [[nodiscard]] const RecentScript &GetRecentScript() const;

        void SetSettings(const Settings &settings) const;

        std::shared_ptr<Settings> GetSettingsPtr();

        [[nodiscard]] const Settings &GetSettings() const;

    private:
        std::shared_ptr<AboutAuthors> about_authors_ = nullptr;
        std::shared_ptr<Info> info_ = nullptr;
        std::shared_ptr<IngameMenu> ingame_menu_ = nullptr;
        std::shared_ptr<IngameSettings> ingame_settings_ = nullptr;
        std::shared_ptr<MainMenu> main_menu_ = nullptr;
        std::shared_ptr<RecentScript> recent_script_ = nullptr;
        std::shared_ptr<Settings> settings_ = nullptr;
    };
}
