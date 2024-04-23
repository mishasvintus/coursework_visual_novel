#include "elements_to_draw.h"

ge::DrawableElements::DrawableElements(DrawableElements &&other) noexcept
    : about_authors_(std::move(other.about_authors_))
    , info_(std::move(other.info_))
    , ingame_menu_(std::move(other.ingame_menu_))
    , ingame_settings_(std::move(other.ingame_settings_))
    , main_menu_(std::move(other.main_menu_))
    , recent_script_(std::move(other.recent_script_))
    , settings_(std::move(other.settings_)) {
}

ge::DrawableElements &ge::DrawableElements::operator=(DrawableElements &&other) noexcept {
    about_authors_ = std::move(other.about_authors_);
    info_ = std::move(other.info_);
    ingame_menu_ = std::move(other.ingame_menu_);
    ingame_settings_ = std::move(other.ingame_settings_);
    main_menu_ = std::move(other.main_menu_);
    recent_script_ = std::move(other.recent_script_);
    settings_ = std::move(other.settings_);
    return *this;
}

void ge::DrawableElements::SetAboutAuthors(const AboutAuthors &about_authors) const {
    *about_authors_ = about_authors;
}

std::shared_ptr<ge::AboutAuthors> ge::DrawableElements::GetAboutAuthorsPtr() {
    return about_authors_;
}

const ge::AboutAuthors &ge::DrawableElements::GetAboutAuthors() const {
    return *about_authors_;
}

void ge::DrawableElements::SetInfo(const Info &info) const {
    *info_ = info;
}

std::shared_ptr<ge::Info> ge::DrawableElements::GetInfoPtr() {
    return info_;
}

const ge::Info &ge::DrawableElements::GetInfo() const {
    return *info_;
}

void ge::DrawableElements::SetIngameMenu(const IngameMenu &ingame_menu) const {
    *ingame_menu_ = ingame_menu;
}

std::shared_ptr<ge::IngameMenu> ge::DrawableElements::GetIngameMenuPtr() {
    return ingame_menu_;
}

const ge::IngameMenu &ge::DrawableElements::GetIngameMenu() const {
    return *ingame_menu_;
}

void ge::DrawableElements::SetIngameSettings(const IngameSettings &ingame_settings) const {
    *ingame_settings_ = ingame_settings;
}

std::shared_ptr<ge::IngameSettings> ge::DrawableElements::GetIngameSettingsPtr() {
    return ingame_settings_;
}

const ge::IngameMenu &ge::DrawableElements::GetIngameSettings() const {
    return *ingame_menu_;
}

void ge::DrawableElements::SetMainMenu(const MainMenu &main_menu) const {
    *main_menu_ = main_menu;
}

std::shared_ptr<ge::MainMenu> ge::DrawableElements::GetMainMenuPtr() {
    return main_menu_;
}

const ge::MainMenu &ge::DrawableElements::GetMainMenu() const {
    return *main_menu_;
}

void ge::DrawableElements::SetRecentScript(const RecentScript &recent_script) const {
    *recent_script_ = recent_script;
}

std::shared_ptr<ge::RecentScript> ge::DrawableElements::GetRecentScriptPtr() {
    return recent_script_;
}

const ge::RecentScript &ge::DrawableElements::GetRecentScript() const {
    return *recent_script_;
}

void ge::DrawableElements::SetSettings(const Settings &settings) const {
    *settings_ = settings;
}

std::shared_ptr<ge::Settings> ge::DrawableElements::GetSettingsPtr() {
    return settings_;
}

const ge::Settings &ge::DrawableElements::GetSettings() const {
    return *settings_;
}
