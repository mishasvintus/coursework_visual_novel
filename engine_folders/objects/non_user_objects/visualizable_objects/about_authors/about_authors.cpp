#include "about_authors.h"

#include <utility>

ge::AboutAuthors::AboutAuthors(const ge::AboutAuthors &about_authors)
        : is_rendered_(about_authors.is_rendered_), text_(about_authors.text_), sfml_basis_(about_authors.sfml_basis_) {
}

ge::AboutAuthors::AboutAuthors(ge::AboutAuthors &about_authors) : is_rendered_(about_authors.is_rendered_),
                                                                  text_(about_authors.text_),
                                                                  sfml_basis_(about_authors.sfml_basis_) {
}

ge::AboutAuthors::AboutAuthors(ge::AboutAuthors &&about_authors) noexcept
        : is_rendered_(about_authors.is_rendered_), text_(std::move(about_authors.text_)),
          sfml_basis_(std::move(about_authors.sfml_basis_)) {
}

ge::AboutAuthors::AboutAuthors(std::wstring text)
        : text_(std::move(text)) {
}

ge::AboutAuthors &ge::AboutAuthors::operator=(const ge::AboutAuthors &about_authors) {
    is_rendered_ = about_authors.is_rendered_;
    text_ = about_authors.text_;
    sfml_basis_ = about_authors.sfml_basis_;
    return *this;
}

ge::AboutAuthors &ge::AboutAuthors::operator=(ge::AboutAuthors &&about_authors) noexcept {
    is_rendered_ = about_authors.is_rendered_;
    text_ = std::move(about_authors.text_);
    sfml_basis_ = std::move(about_authors.sfml_basis_);
    return *this;
}

void ge::AboutAuthors::setText(const std::wstring &text) {
    text_ = text;
}

bool ge::AboutAuthors::renderSfmlBasis(const sf::Vector2u &window_size) {
    //TODO: реализовать
    return true;
}

void ge::AboutAuthors::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::AboutAuthors::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}