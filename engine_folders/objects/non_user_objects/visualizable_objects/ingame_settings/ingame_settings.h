#pragma once

#include "non_user_objects/visualizable_objects/visualizable.h"
#include "non_user_objects/visualizable_objects/settings/settings.h"

namespace ge {
    class IngameSettings : Visualizable {
    public:
        IngameSettings() = default;

        IngameSettings(const IngameSettings &ingame_settings);

        IngameSettings(IngameSettings &ingame_settings);

        IngameSettings(IngameSettings &&ingame_settings) noexcept;

        explicit IngameSettings(std::shared_ptr<ge::Settings> &settings);

        ~IngameSettings() override = default;

        IngameSettings &operator=(const IngameSettings &ingame_settings);

        IngameSettings &operator=(IngameSettings &&ingame_settings) noexcept ;

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override {}

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        std::shared_ptr<ge::Settings> settings_ = nullptr;
        std::shared_ptr<ge::SettingsSfmlBasis> sfml_basis_ = nullptr;
    };
}