#include "settings.h"

#include <utility>
#include <iostream>

bool isParameterValuesCorrect(const std::vector<unsigned int> &parameter_values, unsigned int parameters_quantity,
                              const std::vector<unsigned int> &max_parameter_values) {
    if (parameter_values.size() != parameters_quantity) {
        std::cerr << "Size of given parameter_values_ doesn't match quantity of parameters: " << parameter_values.size()
                  << " != " << parameters_quantity << std::endl;
        return false;
    }
    for (int i = 0; i < parameter_values.size(); ++i) {
        if (parameter_values[i] > max_parameter_values[i]) {
            std::cerr << "Parameter with index " << i << " is bigger than maximum parameter value "
                      << parameter_values[i] << " > " << max_parameter_values[i] << std::endl;
            return false;
        }
    }
    return true;
}

ge::Settings::Settings() {
    selected_row_button_ = PARAMETERS_QUANTITY;
    parameter_values_.resize(PARAMETERS_QUANTITY);
}

ge::Settings::Settings(const ge::Settings &settings) : is_rendered_(settings.is_rendered_),
                                                       parameter_values_(settings.parameter_values_),
                                                       sfml_basis_(settings.sfml_basis_) {
}

ge::Settings::Settings(ge::Settings &settings) : is_rendered_(settings.is_rendered_),
                                                 parameter_values_(settings.parameter_values_),
                                                 sfml_basis_(settings.sfml_basis_) {
    selected_row_button_ = PARAMETERS_QUANTITY;
}

ge::Settings::Settings(ge::Settings &&settings) noexcept: is_rendered_(settings.is_rendered_),
                                                          parameter_values_(std::move(settings.parameter_values_)),
                                                          sfml_basis_(std::move(settings.sfml_basis_)) {
    selected_row_button_ = PARAMETERS_QUANTITY;
}

ge::Settings::Settings(const std::vector<unsigned int> &parameter_values) {
    isParameterValuesCorrect(parameter_values, PARAMETERS_QUANTITY, MAX_PARAMETER_VALUES);
    parameter_values_ = parameter_values;
    selected_row_button_ = PARAMETERS_QUANTITY;
}

ge::Settings &ge::Settings::operator=(const ge::Settings &settings) {
    is_rendered_ = settings.is_rendered_;
    parameter_values_ = settings.parameter_values_;
    sfml_basis_ = settings.sfml_basis_;
    return *this;
}

ge::Settings &ge::Settings::operator=(ge::Settings &&settings) noexcept {
    is_rendered_ = settings.is_rendered_;
    parameter_values_ = std::move(settings.parameter_values_);
    sfml_basis_ = std::move(settings.sfml_basis_);
    return *this;
}

void ge::Settings::setParameterValues(const std::vector<unsigned int> &parameter_values) {
    isParameterValuesCorrect(parameter_values, PARAMETERS_QUANTITY, MAX_PARAMETER_VALUES);
    parameter_values_ = parameter_values;
}

void ge::Settings::setBackgroundFile(const std::string &file) {
    background_file_ = file;
}

bool ge::Settings::renderSfmlBasis(const sf::Vector2u &window_size) {
    if (is_rendered_) {
        return true;
    }
    sfml_basis_ = std::make_shared<SettingsSfmlBasis>();

    // setting background
    if (!sfml_basis_->background_texture.loadFromFile(background_file_)) {
        std::cerr << "File for background image of Settings not found: " << background_file_ << std::endl;
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

    //setting parameters_background
    const sf::Vector2f parameters_background_size = {
            0.6f * static_cast<float>(window_size.x), 0.7f * static_cast<float>(window_size.y)
    };
    const sf::Vector2f parameters_background_position = {
            0.2f * static_cast<float>(window_size.x), 0.1f * static_cast<float>(window_size.y)
    };
    sfml_basis_->parameters_background = sf::RectangleShape(parameters_background_size);
    sfml_basis_->parameters_background.setPosition(parameters_background_position);
    sfml_basis_->parameters_background.setFillColor(BACKGROUND_FILL_COLOR);

    // setting title
    const sf::Vector2f title_position = {
            parameters_background_position.x + parameters_background_size.x * 0.5f,
            parameters_background_position.y + parameters_background_size.y * 0.07f
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

    // setting parameter

    float parameter_left_offset = sfml_basis_->parameters_background.getPosition().x * 1.1f;
    float parameter_up_offset = sfml_basis_->parameters_background.getPosition().y * 1.1f + title_position.y * 0.7f;
    float distance_between_parameters = sfml_basis_->parameters_background.getSize().y * 0.07f;
    auto parameter_character_size = static_cast<unsigned int>(static_cast<float>(window_size.y) * 0.03f);
    sfml_basis_->parameters.resize(PARAMETERS_QUANTITY);
    sfml_basis_->arrow_switches.resize(PARAMETERS_QUANTITY);

    for (int i = 0; i < PARAMETERS_QUANTITY; ++i) {
        sfml_basis_->parameters[i].setFont(sfml_basis_->font);
        sfml_basis_->parameters[i].setCharacterSize(parameter_character_size);
        sfml_basis_->parameters[i].setString(PARAMETERS[i]);
        sfml_basis_->parameters[i].setOutlineThickness(2);
        sfml_basis_->parameters[i].setOrigin(0,
                                             sfml_basis_->parameters[i].getGlobalBounds().getSize().y / 2.0f +
                                             sfml_basis_->parameters[i].getLocalBounds().getPosition().y);
        sfml_basis_->parameters[i].setPosition(parameter_left_offset,
                                               parameter_up_offset +
                                               distance_between_parameters * static_cast<float>(i));

        sfml_basis_->arrow_switches[i].resize(3);
        sfml_basis_->arrow_switches[i][0].setFont(sfml_basis_->font);
        sfml_basis_->arrow_switches[i][0].setCharacterSize(parameter_character_size);
        sfml_basis_->arrow_switches[i][0].setString(L"<");
        sfml_basis_->arrow_switches[i][0].setOutlineThickness(3);
        sfml_basis_->arrow_switches[i][0].setOrigin(
                sfml_basis_->arrow_switches[i][0].getGlobalBounds().getSize() / 2.0f +
                sfml_basis_->arrow_switches[i][0].getLocalBounds().getPosition());
        sfml_basis_->arrow_switches[i][0].setPosition(static_cast<float>(window_size.x) - parameter_left_offset * 1.3f,
                                                      parameter_up_offset +
                                                      distance_between_parameters * static_cast<float>(i));

        sfml_basis_->arrow_switches[i][1].setFont(sfml_basis_->font);
        sfml_basis_->arrow_switches[i][1].setCharacterSize(parameter_character_size);
        sfml_basis_->arrow_switches[i][1].setString(std::to_string(parameter_values_[i]));
        sfml_basis_->arrow_switches[i][1].setOutlineThickness(2);
        sfml_basis_->arrow_switches[i][1].setOrigin(
                sfml_basis_->arrow_switches[i][1].getGlobalBounds().getSize() / 2.0f +
                sfml_basis_->arrow_switches[i][1].getLocalBounds().getPosition());
        sfml_basis_->arrow_switches[i][1].setPosition(static_cast<float>(window_size.x) - parameter_left_offset * 1.2f,
                                                      parameter_up_offset +
                                                      distance_between_parameters * static_cast<float>(i));

        sfml_basis_->arrow_switches[i][2].setFont(sfml_basis_->font);
        sfml_basis_->arrow_switches[i][2].setCharacterSize(parameter_character_size);
        sfml_basis_->arrow_switches[i][2].setString(L">");
        sfml_basis_->arrow_switches[i][2].setOutlineThickness(3);
        sfml_basis_->arrow_switches[i][2].setOrigin(
                sfml_basis_->arrow_switches[i][2].getGlobalBounds().getSize() / 2.0f +
                sfml_basis_->arrow_switches[i][2].getLocalBounds().getPosition());
        sfml_basis_->arrow_switches[i][2].setPosition(static_cast<float>(window_size.x) - parameter_left_offset * 1.1f,
                                                      parameter_up_offset +
                                                      distance_between_parameters * static_cast<float>(i));

    }



    // setting back_button
    sfml_basis_->back_button.setFont(sfml_basis_->font);
    sfml_basis_->back_button.setString(BACK_BUTTON_TEXT);
    sfml_basis_->back_button.setCharacterSize(static_cast<unsigned int>(static_cast<float>(window_size.y) * 0.0256f));
    sfml_basis_->back_button.setOutlineThickness(2);
    sfml_basis_->back_button_background.setFillColor(BACKGROUND_FILL_COLOR);
    sfml_basis_->back_button_background.setOutlineColor(HIGHLIGHT_COLOR);

    sf::Vector2f back_background_size = {sfml_basis_->back_button.getGlobalBounds().getSize().x * 1.3f,
                                         sfml_basis_->back_button.getGlobalBounds().getSize().y * 1.3f};
    sfml_basis_->back_button_background.setSize(back_background_size);
    sfml_basis_->back_button_background.setOutlineThickness(3);

    sf::Vector2f back_background_position = {
            0.5f * parameters_background_size.x + parameters_background_position.x - 0.5f * back_background_size.x,
            parameters_background_position.y + parameters_background_size.y + back_background_size.y};
    sfml_basis_->back_button_background.setPosition(back_background_position);

    sfml_basis_->back_button.setOrigin(
            sfml_basis_->back_button.getGlobalBounds().getSize() / 2.f +
            sfml_basis_->back_button.getLocalBounds().getPosition());
    sfml_basis_->back_button.setPosition(
            sfml_basis_->back_button_background.getPosition() + (sfml_basis_->back_button_background.getSize() / 2.f));

    is_rendered_ = true;
    return true;
}

void ge::Settings::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::Settings::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}

void ge::Settings::moveUp() {
    if (selected_row_button_ == 0) {
        return;
    }

    --selected_row_button_;

    if (!is_rendered_) {
        return;
    }

    if (selected_row_button_ == PARAMETERS_QUANTITY - 1) {
        sfml_basis_->back_button_background.setOutlineColor(sf::Color::Black);
        if (selected_column_button_ == 0) {
            sfml_basis_->arrow_switches[selected_row_button_][0].setOutlineColor(HIGHLIGHT_COLOR);
        } else {
            sfml_basis_->arrow_switches[selected_row_button_][2].setOutlineColor(HIGHLIGHT_COLOR);
        }
    } else {
        if (selected_column_button_ == 0) {
            sfml_basis_->arrow_switches[selected_row_button_ + 1][0].setOutlineColor(sf::Color::Black);
            sfml_basis_->arrow_switches[selected_row_button_][0].setOutlineColor(HIGHLIGHT_COLOR);
        } else {
            sfml_basis_->arrow_switches[selected_row_button_ + 1][2].setOutlineColor(sf::Color::Black);
            sfml_basis_->arrow_switches[selected_row_button_][2].setOutlineColor(HIGHLIGHT_COLOR);
        }
    }
}

void ge::Settings::moveDown() {
    if (selected_row_button_ == PARAMETERS_QUANTITY) {
        return;
    }

    ++selected_row_button_;

    if (!is_rendered_) {
        return;
    }

    if (selected_row_button_ == PARAMETERS_QUANTITY) {
        sfml_basis_->back_button_background.setOutlineColor(HIGHLIGHT_COLOR);
        if (selected_column_button_ == 0) {
            sfml_basis_->arrow_switches[selected_row_button_ - 1][0].setOutlineColor(sf::Color::Black);
        } else {
            sfml_basis_->arrow_switches[selected_row_button_ - 1][2].setOutlineColor(sf::Color::Black);
        }
    } else {
        if (selected_column_button_ == 0) {
            sfml_basis_->arrow_switches[selected_row_button_ - 1][0].setOutlineColor(sf::Color::Black);
            sfml_basis_->arrow_switches[selected_row_button_][0].setOutlineColor(HIGHLIGHT_COLOR);
        } else {
            sfml_basis_->arrow_switches[selected_row_button_ - 1][2].setOutlineColor(sf::Color::Black);
            sfml_basis_->arrow_switches[selected_row_button_][2].setOutlineColor(HIGHLIGHT_COLOR);
        }
    }
}

void ge::Settings::moveLeft() {
    if (selected_row_button_ == PARAMETERS_QUANTITY || selected_column_button_ == 0) {
        return;
    }
    --selected_column_button_;
    if (!is_rendered_) {
        return;
    }
    sfml_basis_->arrow_switches[selected_row_button_][0].setOutlineColor(HIGHLIGHT_COLOR);
    sfml_basis_->arrow_switches[selected_row_button_][2].setOutlineColor(sf::Color::Black);
}

void ge::Settings::moveRight() {
    if (selected_row_button_ == PARAMETERS_QUANTITY || selected_column_button_ == 1) {
        return;
    }
    ++selected_column_button_;
    if (!is_rendered_) {
        return;
    }
    sfml_basis_->arrow_switches[selected_row_button_][2].setOutlineColor(HIGHLIGHT_COLOR);
    sfml_basis_->arrow_switches[selected_row_button_][0].setOutlineColor(sf::Color::Black);
}

void ge::Settings::decreaseParameter() {
    if (selected_row_button_ == PARAMETERS_QUANTITY) {
        return;
    }
    if (parameter_values_[selected_row_button_] > MIN_PARAMETER_VALUES[selected_row_button_]) {
        --parameter_values_[selected_row_button_];
        sfml_basis_->arrow_switches[selected_row_button_][1].setString(
                std::to_string(parameter_values_[selected_row_button_]));
        sf::Vector2f position = sfml_basis_->arrow_switches[selected_row_button_][1].getPosition();
        sfml_basis_->arrow_switches[selected_row_button_][1].setOrigin(
                sfml_basis_->arrow_switches[selected_row_button_][1].getGlobalBounds().getSize() / 2.0f +
                sfml_basis_->arrow_switches[selected_row_button_][1].getLocalBounds().getPosition());
        sfml_basis_->arrow_switches[selected_row_button_][1].setPosition(position);
    }

}

void ge::Settings::increaseParameter() {
    if (selected_row_button_ == PARAMETERS_QUANTITY) {
        return;
    }
    if (parameter_values_[selected_row_button_] < MAX_PARAMETER_VALUES[selected_row_button_]) {
        ++parameter_values_[selected_row_button_];
        sfml_basis_->arrow_switches[selected_row_button_][1].setString(
                std::to_string(parameter_values_[selected_row_button_]));
        sf::Vector2f position = sfml_basis_->arrow_switches[selected_row_button_][1].getPosition();
        sfml_basis_->arrow_switches[selected_row_button_][1].setOrigin(
                sfml_basis_->arrow_switches[selected_row_button_][1].getGlobalBounds().getSize() / 2.0f +
                sfml_basis_->arrow_switches[selected_row_button_][1].getLocalBounds().getPosition());
        sfml_basis_->arrow_switches[selected_row_button_][1].setPosition(position);
    }
}

unsigned int ge::Settings::getSelectedRow() const {
    return selected_row_button_;
}

unsigned int ge::Settings::getSelectedColumn() const {
    return selected_column_button_;
}