#include "info.h"

#include <utility>
#include <iostream>

ge::Info::Info(const ge::Info &info)
    : is_rendered_(info.is_rendered_)
    , title_(info.title_)
    , text_(info.text_)
    , background_(info.background_)
    , sfml_basis_(info.sfml_basis_) {
}

ge::Info::Info(ge::Info &info)
        : is_rendered_(info.is_rendered_)
        , title_(info.title_)
        , text_(info.text_)
        , background_(info.background_)
        , sfml_basis_(info.sfml_basis_) {
}

ge::Info::Info(ge::Info &&info) noexcept
        : is_rendered_(info.is_rendered_)
        , title_(std::move(info.title_))
        , text_(std::move(info.text_))
        , background_(std::move(info.background_))
        , sfml_basis_(std::move(info.sfml_basis_)) {
}

ge::Info::Info(std::wstring info)
    : text_(std::move(info)) {
}

ge::Info &ge::Info::operator=(const ge::Info &info) {
    is_rendered_ = info.is_rendered_;
    title_ = info.title_;
    text_ = info.text_;
    background_ = info.background_;
    sfml_basis_ = info.sfml_basis_;
    return *this;
}

ge::Info &ge::Info::operator=(ge::Info &&info) noexcept {
    is_rendered_ = info.is_rendered_;
    title_ = std::move(info.title_);
    text_ = std::move(info.text_);
    background_ = std::move(info.background_);
    sfml_basis_ = std::move(info.sfml_basis_);
    return *this;
}

void ge::Info::setInfo(const std::wstring& info) {
    text_ = info;
}

void ge::Info::setTitle(const std::wstring &title) {
    title_ = title;
}

void ge::Info::setBackground(const std::string &background) {
    background_ = background;
}

const std::wstring &ge::Info::getInfo() const {
    return text_;
}

const std::wstring &ge::Info::getTitle() const {
    return title_;
}

bool ge::Info::renderSfmlBasis(const sf::Vector2u &window_size) {
    if (is_rendered_) {
        return true;
    }
    sfml_basis_ = std::make_shared<InfoSfmlBasis>();

    if (!sfml_basis_->background_texture.loadFromFile(background_)) {
        std::cerr << "File for background image of Info not found: " << background_ << std::endl;
        return false;
    }
    sfml_basis_->background_sprite.setTexture(sfml_basis_->background_texture);
    sfml_basis_->background_sprite.scale({
                                                 static_cast<float>(window_size.x) / 3840.0f,
                                                 static_cast<float>(window_size.y) / 2160.0f
                                         });
    sfml_basis_->background_sprite.setColor(ABROGATION);

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
    sfml_basis_->back_button_background.setFillColor(BACKGROUND_FILL_COLOR);
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

void ge::Info::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::Info::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}