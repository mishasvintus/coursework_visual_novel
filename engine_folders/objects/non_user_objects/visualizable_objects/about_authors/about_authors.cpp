#include "about_authors.h"

#include <utility>

ge::AboutAuthors::AboutAuthors(const ge::AboutAuthors &about_authors)
        : is_rendered_(about_authors.is_rendered_), text_(about_authors.text_), title_(about_authors.title_),
          sfml_basis_(about_authors.sfml_basis_) {
}

ge::AboutAuthors::AboutAuthors(ge::AboutAuthors &about_authors) : is_rendered_(about_authors.is_rendered_),
                                                                  text_(about_authors.text_),
                                                                  title_(about_authors.title_),
                                                                  sfml_basis_(about_authors.sfml_basis_) {
}

ge::AboutAuthors::AboutAuthors(ge::AboutAuthors &&about_authors) noexcept
        : is_rendered_(about_authors.is_rendered_), text_(std::move(about_authors.text_)),
          title_(std::move(about_authors.title_)), sfml_basis_(std::move(about_authors.sfml_basis_)) {
}

ge::AboutAuthors::AboutAuthors(std::wstring text)
        : text_(std::move(text)) {
}

ge::AboutAuthors &ge::AboutAuthors::operator=(const ge::AboutAuthors &about_authors) {
    is_rendered_ = about_authors.is_rendered_;
    text_ = about_authors.text_;
    title_ = about_authors.title_;
    sfml_basis_ = about_authors.sfml_basis_;
    return *this;
}

ge::AboutAuthors &ge::AboutAuthors::operator=(ge::AboutAuthors &&about_authors) noexcept {
    is_rendered_ = about_authors.is_rendered_;
    text_ = std::move(about_authors.text_);
    title_ = std::move(about_authors.title_);
    sfml_basis_ = std::move(about_authors.sfml_basis_);
    return *this;
}

void ge::AboutAuthors::setText(const std::wstring &text) {
    text_ = text;
}

void ge::AboutAuthors::setBackgroundFile(const std::string &file) {
    background_file_ = file;
}

void ge::AboutAuthors::setTitle(const std::wstring &title) {
    title_ = title;
}

bool ge::AboutAuthors::renderSfmlBasis(const sf::Vector2u &window_size) {
    //TODO: реализовать
    if (is_rendered_) {
        return true;
    }
    sfml_basis_ = std::make_shared<AboutAuthorsSfmlBasis>();
    if (!sfml_basis_->background_texture.loadFromFile(background_file_)) {
        return false;
    }
    sfml_basis_->background_sprite.setTexture(sfml_basis_->background_texture);
    sfml_basis_->background_sprite.scale({
                                                 static_cast<float>(window_size.x) / 3840.0f,
                                                 static_cast<float>(window_size.y) / 2160.0f
                                         });

    if (!sfml_basis_->font.loadFromFile(FONT_NAME)) {
        return false;
    }
    sfml_basis_->text.setFont(sfml_basis_->font);
    sfml_basis_->text.setString(text_);
    sfml_basis_->text.setOutlineThickness(2);
    return true;
}

void ge::AboutAuthors::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::AboutAuthors::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}