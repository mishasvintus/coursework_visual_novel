#include "about_authors.h"

#include <utility>
#include <iostream>

ge::AboutAuthors::AboutAuthors(const ge::AboutAuthors &about_authors)
        : is_rendered_(about_authors.is_rendered_), title_(about_authors.title_), text_(about_authors.text_),
          sfml_basis_(about_authors.sfml_basis_) {
}

ge::AboutAuthors::AboutAuthors(ge::AboutAuthors &about_authors) : is_rendered_(about_authors.is_rendered_),
                                                                  title_(about_authors.title_),
                                                                  text_(about_authors.text_),
                                                                  sfml_basis_(about_authors.sfml_basis_) {
}

ge::AboutAuthors::AboutAuthors(ge::AboutAuthors &&about_authors) noexcept
        : is_rendered_(about_authors.is_rendered_), title_(std::move(about_authors.title_)), text_(std::move(about_authors.text_)),
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

void ge::AboutAuthors::setBackgroundFile(const std::string &file) {
    background_file_ = file;
}

void ge::AboutAuthors::setTitle(const std::wstring &title) {
    title_ = title;
}

bool ge::AboutAuthors::renderSfmlBasis(const sf::Vector2u &window_size) {
    if (is_rendered_) {
        return true;
    }
    sfml_basis_ = std::make_shared<AboutAuthorsSfmlBasis>();

    if (!sfml_basis_->background_texture.loadFromFile(background_file_)) {
        std::cerr << "File for background image of AboutAuthors not found: " << background_file_ << std::endl;
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

    const sf::Vector2f text_background_size = {
            0.6f * static_cast<float>(window_size.x), 0.7f * static_cast<float>(window_size.y)
    };
    const sf::Vector2f text_background_position = {
            0.2f * static_cast<float>(window_size.x), 0.1f * static_cast<float>(window_size.y)
    };

    sfml_basis_->text_background = sf::RectangleShape(text_background_size);
    sfml_basis_->text_background.setPosition(text_background_position);
    sfml_basis_->text_background.setFillColor(BACKGROUND_FILL_COLOR);

    const sf::Vector2f title_position = {
            text_background_position.x + text_background_size.x * 0.5f,
            text_background_position.y + text_background_size.y * 0.07f
    };

    sfml_basis_->title.setFont(sfml_basis_->font);
    sfml_basis_->title.setCharacterSize(static_cast<unsigned int>(window_size.y * 0.04));
    sfml_basis_->title.setString(title_);
    sfml_basis_->title.setFillColor(sf::Color::White);
    sfml_basis_->title.setOutlineColor(sf::Color::Black);
    sfml_basis_->title.setOutlineThickness(2);
    sfml_basis_->title.setOrigin(
            sfml_basis_->title.getGlobalBounds().getSize() / 2.0f + sfml_basis_->title.getLocalBounds().getPosition());
    sfml_basis_->title.setPosition(title_position);

    sfml_basis_->text.setFont(sfml_basis_->font);
    sfml_basis_->text.setCharacterSize(static_cast<unsigned int>(window_size.y * 0.02));
    sfml_basis_->text.setString(text_);
    sfml_basis_->text.setFillColor(sf::Color::White);
    sfml_basis_->text.setOutlineColor(sf::Color::Black);
    sfml_basis_->text.setOutlineThickness(2);

    const sf::Vector2f text_position = {
            text_background_position.x + text_background_size.x / 35.f,
            text_background_position.y + text_background_size.y / 8.f
    };
    sfml_basis_->text.setPosition(text_position);

    sfml_basis_->back_button.setFont(sfml_basis_->font);
    sfml_basis_->back_button.setString(BACK_BUTTON_TEXT);
    sfml_basis_->back_button.setCharacterSize(static_cast<unsigned int>(static_cast<float>(window_size.y) * 0.0256f));
    sfml_basis_->back_button.setOutlineThickness(2);
    sfml_basis_->back_button_background.setFillColor(sf::Color::Transparent);
    sfml_basis_->back_button_background.setOutlineColor(HIGHLIGHT_COLOR);

    sf::Vector2f next_background_size = {sfml_basis_->back_button.getGlobalBounds().getSize().x * 1.3f,
                                         sfml_basis_->back_button.getGlobalBounds().getSize().y * 1.3f};
    sfml_basis_->back_button_background.setSize(next_background_size);
    sfml_basis_->back_button_background.setOutlineThickness(3);

    sf::Vector2f next_background_position = {
            0.5f * text_background_size.x + text_background_position.x - 0.5f * next_background_size.x,
            text_background_position.y + text_background_size.y + next_background_size.y};
    sfml_basis_->back_button_background.setPosition(next_background_position);

    sfml_basis_->back_button.setOrigin(
            sfml_basis_->back_button.getGlobalBounds().getSize() / 2.f + sfml_basis_->back_button.getLocalBounds().getPosition());
    sfml_basis_->back_button.setPosition(
            sfml_basis_->back_button_background.getPosition() + (sfml_basis_->back_button_background.getSize() / 2.f));

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