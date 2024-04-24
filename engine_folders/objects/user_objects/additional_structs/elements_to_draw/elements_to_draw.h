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

        void setAboutAuthors(const AboutAuthors &about_authors) const;

        std::shared_ptr<AboutAuthors> getAboutAuthorsPtr();

        [[nodiscard]] const AboutAuthors &getAboutAuthors() const;

        void setInfo(const Info &info) const;

        std::shared_ptr<Info> getInfoPtr();

        [[nodiscard]] const Info &getInfo() const;

        void setIngameMenu(const IngameMenu &ingame_menu) const;

        std::shared_ptr<IngameMenu> getIngameMenuPtr();

        [[nodiscard]] const IngameMenu &getIngameMenu() const;

        void setIngameSettings(const IngameSettings &ingame_settings) const;

        std::shared_ptr<IngameSettings> getIngameSettingsPtr();

        [[nodiscard]] const IngameMenu &getIngameSettings() const;

        void setMainMenu(const MainMenu &main_menu) const;

        std::shared_ptr<MainMenu> getMainMenuPtr();

        [[nodiscard]] const MainMenu &getMainMenu() const;

        void setRecentScript(const RecentScript &recent_script) const;

        std::shared_ptr<RecentScript> getRecentScriptPtr();

        [[nodiscard]] const RecentScript &getRecentScript() const;

        void setSettings(const Settings &settings) const;

        std::shared_ptr<Settings> getSettingsPtr();

        [[nodiscard]] const Settings &getSettings() const;

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
