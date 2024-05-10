#include "settings.h"

#include <utility>
#include <iostream>

bool isParameterValuesCorrect(const std::vector<unsigned int> &parameter_values, unsigned int parameters_quantity,
                              unsigned int max_parameter_value) {
    if (parameter_values.size() != parameters_quantity) {
        std::cerr << "Size of given parameter_values_ doesn't match quantity of parameters: " << parameter_values.size()
                  << " != " << parameters_quantity << std::endl;
        return false;
    }
    for (int i = 0; i < parameter_values.size(); ++i) {
        if (parameter_values[i] > max_parameter_value) {
            std::cerr << "Parameter with index " << i << " is bigger than maximum parameter value " << parameter_values[i] << " > " << max_parameter_value << std::endl;
            return false;
        }
    }
    return true;
}

ge::Settings::Settings() {
    parameter_values_.resize(PARAMETERS_QUANTITY);
}

ge::Settings::Settings(const ge::Settings &settings) : is_rendered_(settings.is_rendered_),
                                                       parameter_values_(settings.parameter_values_),
                                                       sfml_basis_(settings.sfml_basis_) {
}

ge::Settings::Settings(ge::Settings &settings) : is_rendered_(settings.is_rendered_),
                                                 parameter_values_(settings.parameter_values_),
                                                 sfml_basis_(settings.sfml_basis_) {
}

ge::Settings::Settings(ge::Settings &&settings) noexcept: is_rendered_(settings.is_rendered_),
                                                          parameter_values_(std::move(settings.parameter_values_)),
                                                          sfml_basis_(std::move(settings.sfml_basis_)) {
}

ge::Settings::Settings(const std::vector<unsigned int> &parameter_values) {
    isParameterValuesCorrect(parameter_values, PARAMETERS_QUANTITY, MAX_PARAMETER_VALUE);
    parameter_values_ = parameter_values;
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
    isParameterValuesCorrect(parameter_values, PARAMETERS_QUANTITY, MAX_PARAMETER_VALUE);
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
            0.6f * static_cast<float>(window_size.x), 0.7f * static_cast<float>(window_size.y)
    };
    const sf::Vector2f title_background_position = {
            0.2f * static_cast<float>(window_size.x), 0.1f * static_cast<float>(window_size.y)
    };

    sfml_basis_->parameters_background = sf::RectangleShape(title_background_size);
    sfml_basis_->parameters_background.setPosition(title_background_position);
    sfml_basis_->parameters_background.setFillColor(sf::Color(66, 84, 127));

    sfml_basis_->title.setFont(sfml_basis_->font);
    sfml_basis_->title.setCharacterSize(static_cast<unsigned int>(window_size.y * 0.02));
    sfml_basis_->title.setString(TITLE);
    sfml_basis_->title.setFillColor(sf::Color::White);
    sfml_basis_->title.setOutlineColor(sf::Color::Black);
    sfml_basis_->title.setOutlineThickness(2);

    const sf::Vector2f title_position = {
            title_background_position.x + title_background_size.x / 2.325f,
            title_background_position.y + title_background_size.y / 100
    };

    sfml_basis_->title.setPosition(title_position);

    sfml_basis_->back_button.setFont(sfml_basis_->font);
    sfml_basis_->back_button.setString(BACK_BUTTON_TEXT);
    sfml_basis_->back_button.setCharacterSize(static_cast<unsigned int>(static_cast<float>(window_size.y) * 0.0256f));
    sfml_basis_->back_button.setOutlineThickness(2);
    sfml_basis_->back_button_background.setFillColor(sf::Color::Transparent);
    sfml_basis_->back_button_background.setOutlineColor(sf::Color::White);

    sf::Vector2f next_background_size = {sfml_basis_->back_button.getGlobalBounds().getSize().x * 1.3f,
                                         sfml_basis_->back_button.getGlobalBounds().getSize().y * 1.3f};
    sfml_basis_->back_button_background.setSize(next_background_size);
    sfml_basis_->back_button_background.setOutlineThickness(3);

    sf::Vector2f next_background_position = {
            0.5f * title_background_size.x + title_background_position.x - 0.5f * next_background_size.x,
            title_background_position.y + title_background_size.y + next_background_size.y};
    sfml_basis_->back_button_background.setPosition(next_background_position);

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