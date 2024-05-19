#include "ingame_settings.h"

ge::IngameSettings::IngameSettings(const IngameSettings& ingame_settings)
    : settings_(ingame_settings.settings_) {
}

ge::IngameSettings::IngameSettings(ge::IngameSettings &ingame_settings)
    : settings_(ingame_settings.settings_) {
}

ge::IngameSettings::IngameSettings(ge::IngameSettings &&ingame_settings) noexcept
    :settings_(std::move(ingame_settings.settings_)) {
}

ge::IngameSettings::IngameSettings(std::shared_ptr<ge::Settings> &settings)
    :settings_(settings) {
}

ge::IngameSettings &ge::IngameSettings::operator=(const ge::IngameSettings &ingame_settings) {
    settings_ = ingame_settings.settings_;
    return *this;
}

ge::IngameSettings &ge::IngameSettings::operator=(ge::IngameSettings &&ingame_settings) noexcept {
    settings_ = std::move(ingame_settings.settings_);
    return *this;
}

void ge::IngameSettings::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::IngameSettings::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}