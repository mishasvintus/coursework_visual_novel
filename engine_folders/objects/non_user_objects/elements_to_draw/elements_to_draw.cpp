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

void ge::DrawableElements::setAboutAuthors(const std::shared_ptr<ge::AboutAuthors> &about_authors) {
    about_authors_ = about_authors;
}

std::shared_ptr<ge::AboutAuthors> ge::DrawableElements::getAboutAuthorsPtr() {
    return about_authors_;
}

const ge::AboutAuthors &ge::DrawableElements::getAboutAuthors() const {
    return *about_authors_;
}

ge::AboutAuthors &ge::DrawableElements::putAboutAuthors() const {
    return *about_authors_;
}

void ge::DrawableElements::setInfo(const std::shared_ptr<Info> &info) {
    info_ = info;
}

std::shared_ptr<ge::Info> ge::DrawableElements::getInfoPtr() {
    return info_;
}

const ge::Info &ge::DrawableElements::getInfo() const {
    return *info_;
}

ge::Info &ge::DrawableElements::putInfo() const {
    return *info_;
}


void ge::DrawableElements::setIngameMenu(const std::shared_ptr<IngameMenu> &ingame_menu) {
    ingame_menu_ = ingame_menu;
}

std::shared_ptr<ge::IngameMenu> ge::DrawableElements::getIngameMenuPtr() {
    return ingame_menu_;
}

const ge::IngameMenu &ge::DrawableElements::getIngameMenu() const {
    return *ingame_menu_;
}

ge::IngameMenu &ge::DrawableElements::putIngameMenu() const {
    return *ingame_menu_;
}

void ge::DrawableElements::setIngameSettings(const std::shared_ptr<IngameSettings> &ingame_settings) {
    ingame_settings_ = ingame_settings;
}

std::shared_ptr<ge::IngameSettings> ge::DrawableElements::getIngameSettingsPtr() {
    return ingame_settings_;
}

const ge::IngameSettings &ge::DrawableElements::getIngameSettings() const {
    return *ingame_settings_;
}

ge::IngameSettings &ge::DrawableElements::putIngameSettings() const {
    return *ingame_settings_;
}

void ge::DrawableElements::setMainMenu(const std::shared_ptr<MainMenu> &main_menu) {
    main_menu_ = main_menu;
}

std::shared_ptr<ge::MainMenu> ge::DrawableElements::getMainMenuPtr() {
    return main_menu_;
}

const ge::MainMenu &ge::DrawableElements::getMainMenu() const {
    return *main_menu_;
}

ge::MainMenu &ge::DrawableElements::putMainMenu() const {
    return *main_menu_;
}

void ge::DrawableElements::setRecentScript(const std::shared_ptr<RecentScript> &recent_script) {
    recent_script_ = recent_script;
}

std::shared_ptr<ge::RecentScript> ge::DrawableElements::getRecentScriptPtr() {
    return recent_script_;
}

const ge::RecentScript &ge::DrawableElements::getRecentScript() const {
    return *recent_script_;
}

ge::RecentScript &ge::DrawableElements::putRecentScript() const {
    return *recent_script_;
}

void ge::DrawableElements::setSettings(const std::shared_ptr<Settings> &settings) {
    settings_ = settings;
}

std::shared_ptr<ge::Settings> ge::DrawableElements::getSettingsPtr() {
    return settings_;
}

const ge::Settings &ge::DrawableElements::getSettings() const {
    return *settings_;
}

ge::Settings &ge::DrawableElements::putSettings() const {
    return *settings_;
}

void ge::DrawableElements::setScene(const std::shared_ptr<ge::Scene> &scene) {
    scene_ = scene;
}

std::shared_ptr<ge::Scene> ge::DrawableElements::getScenePtr() {
    return scene_;
}

[[nodiscard]] const ge::Scene &ge::DrawableElements::getScene() const {
    return *scene_;
}

[[nodiscard]] ge::Scene &ge::DrawableElements::putScene() const {
    return *scene_;
}
