#include "main_menu.h"

void checkingCorrectness(const unsigned int selected_button, const unsigned int upper_limit_selected_button,
                         const std::string &title, const unsigned int upper_limit_title) {
    if (selected_button > upper_limit_selected_button - 1 || title.length() > upper_limit_title) {
        throw std::invalid_argument("so big number in selected_button\n");
    }
}

ge::MainMenu::MainMenu(const MainMenu &main_menu)
    : title_(main_menu.title_)
      , selected_button_(main_menu.selected_button_)
      , is_rendered_(main_menu.is_rendered_)
      , sfml_basis_(main_menu.sfml_basis_) {
}

ge::MainMenu::MainMenu(MainMenu &main_menu)
    : title_(main_menu.title_)
      , selected_button_(main_menu.selected_button_)
      , is_rendered_(main_menu.is_rendered_)
      , sfml_basis_(main_menu.sfml_basis_) {
}

ge::MainMenu::MainMenu(MainMenu &&main_menu) noexcept
    : title_(std::move(main_menu.title_))
      , selected_button_(main_menu.selected_button_)
      , is_rendered_(main_menu.is_rendered_)
      , sfml_basis_(std::move(main_menu.sfml_basis_)) {
}

ge::MainMenu &ge::MainMenu::operator=(const MainMenu &main_menu) {
    selected_button_ = main_menu.selected_button_;
    title_ = main_menu.title_;
    is_rendered_ = main_menu.is_rendered_;
    sfml_basis_ = main_menu.sfml_basis_;
    return *this;
}

ge::MainMenu &ge::MainMenu::operator=(MainMenu &&main_menu) noexcept {
    selected_button_ = main_menu.selected_button_;
    title_ = std::move(main_menu.title_);
    is_rendered_ = main_menu.is_rendered_;
    sfml_basis_ = std::move(main_menu.sfml_basis_);
    return *this;
}

void ge::MainMenu::MoveUp() {
    if (selected_button_ == TOP_BUTTON_INDEX) {
        return;
    }
    if (is_rendered_) {
        sfml_basis_->buttons_[selected_button_].setFillColor(sf::Color::White);
        sfml_basis_->buttons_[selected_button_ - 1].setFillColor(sf::Color::Blue);
    }
    --selected_button_;
}

void ge::MainMenu::MoveDown() {
    if (selected_button_ == BOTTOM_BUTTON_INDEX) {
        return;
    }
    if (is_rendered_) {
        sfml_basis_->buttons_[selected_button_].setFillColor(sf::Color::White);
        sfml_basis_->buttons_[selected_button_ + 1].setFillColor(sf::Color::Blue);
    }
    ++selected_button_;
}

void ge::MainMenu::setTitle(const std::string &title) {
    checkingCorrectness(selected_button_, QUANTITY_OF_BUTTONS, title, UPPER_BOUND_TITLE_LENGTH);
    title_ = title;
}

unsigned int ge::MainMenu::getSelectedButton() const {
    return selected_button_;
}

bool ge::MainMenu::renderSfmlBasis(const sf::Vector2u &window_size) {
    if (is_rendered_) {
        return true;
    }

    sfml_basis_ = std::make_shared<MainMenuSfmlBasis>();

    sf::Font font;
    if (!font.loadFromFile(FONT_NAME)) {
        return false;
    }

    const sf::Vector2f title_background_size = {
        0.4f * static_cast<float>(window_size.x), 0.18f * static_cast<float>(window_size.y)
    };
    const sf::Vector2f title_background_position = {
        0.3f * static_cast<float>(window_size.x), 0.12f * static_cast<float>(window_size.y)
    };
    sfml_basis_->title_background_ = sf::RectangleShape(title_background_size);
    sfml_basis_->title_background_.setFillColor(sf::Color(56, 87, 97));

    sfml_basis_->title_.setFont(font);
    sfml_basis_->title_.setString(title_);
    sfml_basis_->title_.setFillColor(sf::Color::White);
    sfml_basis_->title_.setOutlineColor(sf::Color::Black);
    sfml_basis_->title_.setOutlineThickness(2);
    sfml_basis_->title_.setOrigin(sfml_basis_->title_.getLocalBounds().width / 2,
                                  sfml_basis_->title_.getLocalBounds().height / 2);
    sf::Vector2f title_position = {
        title_background_position.x + title_background_size.x / 2,
        title_background_position.y + title_background_size.y / 2
    };
    sfml_basis_->title_.setPosition(title_background_position);

    sfml_basis_->buttons_.resize(QUANTITY_OF_BUTTONS);

    for (int i = 0; i < QUANTITY_OF_BUTTONS; ++i) {
        sfml_basis_->buttons_[i].setFont(font);
        sfml_basis_->buttons_[i].setString(BUTTONS[i]);
        sfml_basis_->buttons_[i].setFillColor(sf::Color::White);
        sfml_basis_->buttons_[i].setOutlineColor(sf::Color::Black);
        sfml_basis_->buttons_[i].setOutlineThickness(2);
        sfml_basis_->buttons_[i].setOrigin(sfml_basis_->buttons_[i].getLocalBounds().width / 2,
                                           sfml_basis_->buttons_[i].getLocalBounds().height / 2);
        sf::Vector2f button_position = {
            0.5f * static_cast<float>(window_size.x),
            0.31f * static_cast<float>(window_size.y) + 0.075f * static_cast<float>(window_size.y * i)
        };
        sfml_basis_->buttons_[i].setPosition(button_position);
    }
    is_rendered_ = true;
    return true;
}

void ge::MainMenu::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::MainMenu::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}
