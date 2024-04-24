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

        void setAboutAuthors(const ge::AboutAuthors &about_authors) const;

        std::shared_ptr<ge::AboutAuthors> getAboutAuthorsPtr();

        [[nodiscard]] const ge::AboutAuthors &getAboutAuthors() const;

        [[nodiscard]] ge::AboutAuthors &putAboutAuthors() const;

        void setInfo(const ge::Info &info) const;

        std::shared_ptr<ge::Info> getInfoPtr();

        [[nodiscard]] const ge::Info &getInfo() const;

        [[nodiscard]] ge::Info putInfo() const;

        void setIngameMenu(const ge::IngameMenu &ingame_menu) const;

        std::shared_ptr<ge::IngameMenu> getIngameMenuPtr();

        [[nodiscard]] const ge::IngameMenu &getIngameMenu() const;

        [[nodiscard]] ge::IngameMenu &putIngameMenu() const;

        void setIngameSettings(const ge::IngameSettings &ingame_settings) const;

        std::shared_ptr<ge::IngameSettings> getIngameSettingsPtr();

        [[nodiscard]] const ge::IngameSettings &getIngameSettings() const;

        [[nodiscard]] ge::IngameSettings &putIngameSettings() const;

        void setMainMenu(const ge::MainMenu &main_menu) const;

        std::shared_ptr<ge::MainMenu> getMainMenuPtr();

        [[nodiscard]] const ge::MainMenu &getMainMenu() const;

        [[nodiscard]] ge::MainMenu &putMainMenu() const;

        void setRecentScript(const ge::RecentScript &recent_script) const;

        std::shared_ptr<ge::RecentScript> getRecentScriptPtr();

        [[nodiscard]] const ge::RecentScript &getRecentScript() const;

        [[nodiscard]] ge::RecentScript &putRecentScript() const;

        void setSettings(const ge::Settings &settings) const;

        std::shared_ptr<ge::Settings> getSettingsPtr();

        [[nodiscard]] const ge::Settings &getSettings() const;

        [[nodiscard]] ge::Settings &putSettings() const;

    private:
        std::shared_ptr<ge::AboutAuthors> about_authors_ = nullptr;
        std::shared_ptr<Info> info_ = nullptr;
        std::shared_ptr<ge::IngameMenu> ingame_menu_ = nullptr;
        std::shared_ptr<ge::IngameSettings> ingame_settings_ = nullptr;
        std::shared_ptr<ge::MainMenu> main_menu_ = nullptr;
        std::shared_ptr<ge::RecentScript> recent_script_ = nullptr;
        std::shared_ptr<ge::Settings> settings_ = nullptr;
    };
}
