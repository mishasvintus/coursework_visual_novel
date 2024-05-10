#pragma once

#include "non_user_objects/visualizable_objects/visualizable.h"
#include "settings_sfml_basis.h"

namespace ge {
    class Settings : Visualizable {
    public:
        Settings();

        Settings(const Settings &settings);

        Settings(Settings &settings);

        Settings(Settings &&settings) noexcept;

        Settings(const std::vector<unsigned int> &parameter_values);

        ~Settings() override = default;

        Settings &operator=(const Settings &settings);

        Settings &operator=(Settings &&settings) noexcept;

        void setParameterValues(const std::vector<unsigned int> &parameter_values);

        void setBackgroundFile(const std::string &file);

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;


        bool is_rendered_ = false;
        std::vector<unsigned int> parameter_values_ = {100};
        std::string background_file_ = "engine_folders/data/images/locations/abstraction.PNG";
        std::shared_ptr<SettingsSfmlBasis> sfml_basis_ = nullptr;


        const std::wstring TITLE = L"НАСТРОЙКИ";
        const std::vector<std::wstring> PARAMETERS = {L"Громкость звука"};
        const unsigned int PARAMETERS_QUANTITY = 1;
        const std::wstring BACK_BUTTON_TEXT = L"Назад";
        const unsigned int MAX_PARAMETER_VALUE = 100;
        const sf::Color BACKGROUND_FILL_COLOR = sf::Color(66, 84, 127);
        const sf::Color HIGHLIGHT_COLOR = sf::Color(229,228,226);
    };
}