#include <iostream>
#include "ingame_menu.h"

ge::IngameMenu::IngameMenu(const ge::IngameMenu &ingame_menu)
        : is_rendered_(ingame_menu.is_rendered_)
        , background_(ingame_menu.background_)
        , sfml_basis_(ingame_menu.sfml_basis_)
        , selected_row_(ingame_menu.selected_row_) {
}

ge::IngameMenu::IngameMenu(ge::IngameMenu &ingame_menu)
        : is_rendered_(ingame_menu.is_rendered_)
        , background_(ingame_menu.background_)
        , sfml_basis_(ingame_menu.sfml_basis_)
        , selected_row_(ingame_menu.selected_row_) {
}

ge::IngameMenu::IngameMenu(ge::IngameMenu &&ingame_menu) noexcept
        : is_rendered_(ingame_menu.is_rendered_)
        , background_(std::move(ingame_menu.background_))
        , sfml_basis_(std::move(ingame_menu.sfml_basis_))
        , selected_row_(ingame_menu.selected_row_) {
}

ge::IngameMenu &ge::IngameMenu::operator=(const ge::IngameMenu &ingame_menu) {
    is_rendered_ = ingame_menu.is_rendered_;
    background_ = ingame_menu.background_;
    sfml_basis_ = ingame_menu.sfml_basis_;
    selected_row_ = ingame_menu.selected_row_;
    return *this;
}

ge::IngameMenu &ge::IngameMenu::operator=(ge::IngameMenu &&ingame_menu) noexcept {
    is_rendered_ = ingame_menu.is_rendered_;
    background_ = std::move(ingame_menu.background_);
    sfml_basis_ = std::move(ingame_menu.sfml_basis_);
    selected_row_ = ingame_menu.selected_row_;
    return *this;
}

void ge::IngameMenu::setBackground(const std::string &background) {
    background_ = background;
}

void ge::IngameMenu::moveUp() {
    if (selected_row_ == TOP_BUTTON_INDEX) {
        return;
    }
    if (is_rendered_) {
        sfml_basis_->buttons[selected_row_].setFillColor(sf::Color::White);
        sfml_basis_->buttons[selected_row_ - 1].setFillColor(sf::Color(100, 131, 171));
    }
    --selected_row_;
}

void ge::IngameMenu::moveDown() {
    if (selected_row_ == BOTTOM_BUTTON_INDEX) {
        return;
    }
    if (is_rendered_) {
        sfml_basis_->buttons[selected_row_].setFillColor(sf::Color::White);
        sfml_basis_->buttons[selected_row_ + 1].setFillColor(sf::Color(100, 131, 171));
    }
    ++selected_row_;
}

unsigned int ge::IngameMenu::getSelectedRow() const {
    return selected_row_;
}

bool ge::IngameMenu::renderSfmlBasis(const sf::Vector2u &window_size) {
    if (is_rendered_) {
        return true;
    }
    if (!cache_manager_) {
        std::cerr << "Cache_manager wasn't set in IngameMenu" << std::endl;
        return false;
    }

    sfml_basis_ = std::make_shared<IngameMenuSfmlBasis>();

    if (!cache_manager_->loadImage(background_, false)) {
        std::cerr << "Can't load file for background image of IngameMenu: " << background_ << std::endl;
        return false;
    }
    sfml_basis_->background_sprite.setTexture(cache_manager_->getTextureRef(background_));
    sfml_basis_->background_sprite.scale({
                                                 static_cast<float>(window_size.x) / 3840.0f,
                                                 static_cast<float>(window_size.y) / 2160.0f
                                         });
    sfml_basis_->background_sprite.setColor(ABROGATION);

    if (!sfml_basis_->font.loadFromFile(FONT_NAME)) {
        return false;
    }
    const sf::Vector2f window_shape_size = {
            0.3f * static_cast<float>(window_size.x), 0.6f * static_cast<float>(window_size.y)
    };
    const sf::Vector2f window_shape_position = {
            0.35f * static_cast<float>(window_size.x), 0.2f * static_cast<float>(window_size.y)
    };
    sfml_basis_->window_shape = sf::RectangleShape(window_shape_size);
    sfml_basis_->window_shape.setPosition(window_shape_position);
    sfml_basis_->window_shape.setFillColor(BACKGROUND_FILL_COLOR);

    const sf::Vector2f title_position = {
            window_shape_position.x + window_shape_size.x * 0.5f,
            window_shape_position.y + window_shape_size.y * 0.07f
    };

    sfml_basis_->title.setFont(sfml_basis_->font);
    sfml_basis_->title.setCharacterSize(static_cast<unsigned int>(window_size.y * 0.04));
    sfml_basis_->title.setString(TITLE);
    sfml_basis_->title.setFillColor(sf::Color::White);
    sfml_basis_->title.setOutlineColor(sf::Color::Black);
    sfml_basis_->title.setOutlineThickness(2);
    sfml_basis_->title.setOrigin(
            sfml_basis_->title.getGlobalBounds().getSize() / 2.0f + sfml_basis_->title.getLocalBounds().getPosition());
    sfml_basis_->title.setPosition(title_position);

    sfml_basis_->buttons.resize(BUTTONS_QUANTITY);
    for (int i = 0; i < BUTTONS_QUANTITY; ++i) {
        sfml_basis_->buttons[i].setFont(sfml_basis_->font);
        sfml_basis_->buttons[i].setString(BUTTONS[i]);
        sfml_basis_->buttons[i].setCharacterSize(static_cast<unsigned int>(window_size.y * 0.025));
        sfml_basis_->buttons[i].setOutlineColor(sf::Color::Black);
        sfml_basis_->buttons[i].setOutlineThickness(2);
        if (i == 0) {
            sfml_basis_->buttons[i].setFillColor(sf::Color(100, 131, 171));
        } else {
            sfml_basis_->buttons[i].setFillColor(sf::Color::White);
        }

        sfml_basis_->buttons[i].setOrigin(sfml_basis_->buttons[i].getLocalBounds().width / 2,
                                          sfml_basis_->buttons[0].getLocalBounds().height / 2);
        sf::Vector2f button_position = {
                0.5f * static_cast<float>(window_size.x),
                0.39f * static_cast<float>(window_size.y) + 0.075f * static_cast<float>(window_size.y * i)
        };
        sfml_basis_->buttons[i].setPosition(button_position);
    }

    is_rendered_ = true;
    return true;
}

void ge::IngameMenu::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::IngameMenu::getSfmlBasis() {
    return std::static_pointer_cast<ge::SfmlBasis>(sfml_basis_);
}