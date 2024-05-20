#pragma once

#include "game_mode.h"
#include "non_user_objects/visualizable_objects/visualizable.h"
#include "settings_sfml_basis.h"
#include "cache_manager.h"
namespace ge {
    class Settings : Visualizable {
    public:
        Settings();

        Settings(const Settings &settings);

        Settings(Settings &settings);

        Settings(Settings &&settings) noexcept;

        explicit Settings(const std::vector<unsigned int> &parameter_values);

        ~Settings() override = default;

        Settings &operator=(const Settings &settings);

        Settings &operator=(Settings &&settings) noexcept;

        void setParameterValues(const std::vector<unsigned int> &parameter_values);

        void setBackgroundFile(const std::string &file);

        void setBackground(const std::string &background);

        void setReturnPoint(ge::GameMode return_point);

        void moveUp();

        void moveDown();

        void moveLeft();

        void moveRight();

        void decreaseParameter();

        void increaseParameter();

        [[nodiscard]] unsigned int getSelectedRow() const;

        [[nodiscard]] unsigned int getSelectedColumn() const;

        [[nodiscard]] const std::vector<unsigned int> &getParameterValues() const;

        const std::string &getBackground();

        [[nodiscard]] ge::GameMode getReturnPoint() const;

        void setCacheManager(std::shared_ptr<CacheManager> cache_manager);

        const CacheManager &getCacheManager();

        const unsigned int BACK_BUTTON_ROW = 1;
        const unsigned int LEFT = 0;
        const unsigned int RIGHT = 1;
        const size_t SOUND_VOLUME_INDEX = 0;
    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        bool is_darkening_ = false;
        ge::GameMode return_point_ = ge::GameMode::MainMenu;
        std::vector<unsigned int> parameter_values_ = {80};
        std::string background_;
        std::shared_ptr<SettingsSfmlBasis> sfml_basis_ = nullptr;
        std::shared_ptr<CacheManager> cache_manager_ = nullptr;

        unsigned int selected_row_button_;
        unsigned int selected_column_button_ = 0;

        const std::wstring TITLE = L"НАСТРОЙКИ";
        const unsigned int PARAMETERS_QUANTITY = 1;
        const std::vector<std::wstring> PARAMETERS = {L"Громкость звука"};
        const std::vector<unsigned int> MIN_PARAMETER_VALUES = {0};
        const std::vector<unsigned int> MAX_PARAMETER_VALUES = {100};
        const std::wstring BACK_BUTTON_TEXT = L"Назад";
        const sf::Color DARKENING_COLOR = sf::Color(105, 105, 105);
        const sf::Color BACKGROUND_FILL_COLOR = sf::Color(66, 84, 127, 160);
        const sf::Color HIGHLIGHT_COLOR = sf::Color(229, 228, 226);
    };
}