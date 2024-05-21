#pragma once

#include <queue>
#include "non_user_objects/visualizable_objects/visualizable.h"
#include "recent_script_sfml_basis.h"

namespace ge {
    class RecentScript : Visualizable {
    public:
        RecentScript() = default;

        RecentScript(const RecentScript &recent_script);

        RecentScript(RecentScript &recent_script);

        RecentScript(RecentScript &&recent_script) noexcept;

        ~RecentScript() override = default;

        RecentScript &operator=(const RecentScript &recent_script);

        RecentScript &operator=(RecentScript &&recent_script) noexcept;

        void setTitle(const std::wstring &title);

        void setBackground(const std::string& background);

        void setScript(const std::queue<std::pair<std::wstring, std::wstring>>& script);

        void emplaceBack(const std::pair<std::wstring, std::wstring>& step);

        [[nodiscard]] const std::wstring& getTitle() const;

        [[nodiscard]] const std::string& getBackground() const;

        [[nodiscard]] const std::queue<std::pair<std::wstring, std::wstring>>& getScript() const;

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        std::wstring title_ = L"СЦЕНАРИЙ";
        std::queue<std::pair<std::wstring, std::wstring>> script_step_;
        std::string background_;
        std::shared_ptr<RecentScriptSfmlBasis> sfml_basis_ = nullptr;
        const size_t MAX_HISTORY_LENGTH = 6;
        const std::wstring ACTION = L"ACTION";
        const std::wstring BACK_BUTTON_TEXT = L"Назад";
        const sf::Color ABROGATION = sf::Color(105, 105, 105);
        const sf::Color BACKGROUND_FILL_COLOR = sf::Color(66, 84, 127, 240);
        const sf::Color HIGHLIGHT_COLOR = sf::Color(229, 228, 226);
    };
}