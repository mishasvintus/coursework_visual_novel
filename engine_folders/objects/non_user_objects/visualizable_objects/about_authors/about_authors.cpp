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

    const sf::Vector2f title_background_size = {
            0.4f * static_cast<float>(window_size.x), 0.18f * static_cast<float>(window_size.y)
    };
    const sf::Vector2f title_background_position = {
            0.3f * static_cast<float>(window_size.x), 0.12f * static_cast<float>(window_size.y)
    };

    sfml_basis_->title_background = sf::RectangleShape(title_background_size);
    sfml_basis_->title_background.setPosition(title_background_position);
    sfml_basis_->title_background.setFillColor(sf::Color(66, 84, 127));

    sfml_basis_->title.setFont(sfml_basis_->font);
    sfml_basis_->title.setCharacterSize(static_cast<unsigned int>(window_size.y * 0.05));
    sfml_basis_->title.setString(title_);
    sfml_basis_->title.setFillColor(sf::Color::White);
    sfml_basis_->title.setOutlineColor(sf::Color::Black);
    sfml_basis_->title.setOutlineThickness(2);
    sfml_basis_->title.setOrigin(sfml_basis_->title.getLocalBounds().width / 2,
                                  sfml_basis_->title.getLocalBounds().height / 2);
    const sf::Vector2f title_position = {
            title_background_position.x + title_background_size.x / 2,
            title_background_position.y + title_background_size.y / 2
    };
    sfml_basis_->title.setPosition(title_position);

    is_rendered_ = true;
    return true;
}

void ge::AboutAuthors::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::AboutAuthors::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}