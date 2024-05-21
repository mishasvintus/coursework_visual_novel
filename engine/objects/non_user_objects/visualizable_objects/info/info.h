#pragma once

#include "non_user_objects/visualizable_objects/visualizable.h"
#include "info_sfml_basis.h"

namespace ge {
    class Info : Visualizable {
    public:
        Info() = default;

        Info(const Info &info);

        Info(Info &info);

        Info(Info &&info) noexcept;

        explicit Info(std::wstring info);

        ~Info() override = default;

        Info &operator=(const Info &info);

        Info &operator=(Info &&info) noexcept;

        void setInfo(const std::wstring& info);

        void setTitle(const std::wstring &title);

        void setBackground(const std::string& background);

        [[nodiscard]] const std::wstring& getInfo() const;

        [[nodiscard]] const std::wstring& getTitle() const;

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        std::wstring title_ = L"ИНФОРМАЦИЯ";
        std::wstring text_;
        const std::wstring BACK_BUTTON_TEXT = L"Назад";
        std::string background_;
        std::shared_ptr<InfoSfmlBasis> sfml_basis_ = nullptr;
        const sf::Color ABROGATION = sf::Color(105, 105, 105);
        const sf::Color BACKGROUND_FILL_COLOR = sf::Color(66, 84, 127, 240);
        const sf::Color HIGHLIGHT_COLOR = sf::Color(229,228,226);
    };
}