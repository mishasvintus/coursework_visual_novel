#pragma once

#include "non_user_objects/visualizable_objects/visualizable.h"
#include "about_authors_sfml_basis.h"

namespace ge {
    class AboutAuthors : Visualizable {
    public:
        AboutAuthors() = default;

        AboutAuthors(const AboutAuthors &about_authors);

        AboutAuthors(AboutAuthors &about_authors);

        AboutAuthors(AboutAuthors &&about_authors) noexcept;

        explicit AboutAuthors(std::wstring text);

        ~AboutAuthors() override = default;

        AboutAuthors &operator=(const AboutAuthors &about_authors);

        AboutAuthors &operator=(AboutAuthors &&about_authors) noexcept;

        void setText(const std::wstring &text);

        void setTitle(const std::wstring &title);

        void setBackgroundFile(const std::string& file);

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        std::wstring text_;
        std::wstring title_;
        std::string background_file_;
        std::shared_ptr<AboutAuthorsSfmlBasis> sfml_basis_ = nullptr;
    };
}