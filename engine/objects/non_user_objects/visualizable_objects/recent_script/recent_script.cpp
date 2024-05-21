#include <iostream>
#include "recent_script.h"

ge::RecentScript::RecentScript(ge::RecentScript &recent_script)
    : is_rendered_(recent_script.is_rendered_)
    , title_(recent_script.title_)
    , script_step_(recent_script.script_step_)
    , background_(recent_script.background_)
    , sfml_basis_(recent_script.sfml_basis_) {
}

ge::RecentScript::RecentScript(const ge::RecentScript &recent_script)
    : is_rendered_(recent_script.is_rendered_)
    , title_(recent_script.title_)
    , script_step_(recent_script.script_step_)
    , background_(recent_script.background_)
    , sfml_basis_(recent_script.sfml_basis_) {
}

ge::RecentScript::RecentScript(ge::RecentScript &&recent_script) noexcept
    : is_rendered_(recent_script.is_rendered_)
    , title_(std::move(recent_script.title_))
    , script_step_(std::move(recent_script.script_step_))
    , background_(std::move(recent_script.background_))
    , sfml_basis_(std::move(recent_script.sfml_basis_)) {
}

ge::RecentScript &ge::RecentScript::operator=(const ge::RecentScript &recent_script) {
    is_rendered_ = recent_script.is_rendered_;
    title_ = recent_script.title_;
    script_step_ = recent_script.script_step_;
    background_ = recent_script.background_;
    sfml_basis_ = recent_script.sfml_basis_;
    return *this;
}

ge::RecentScript &ge::RecentScript::operator=(ge::RecentScript &&recent_script)  noexcept {
    is_rendered_ = recent_script.is_rendered_;
    title_ = std::move(recent_script.title_);
    script_step_ = std::move(recent_script.script_step_);
    background_ = std::move(recent_script.background_);
    sfml_basis_ = std::move(recent_script.sfml_basis_);
    return *this;
}

void ge::RecentScript::setTitle(const std::wstring &title) {
    title_ = title;
}

void ge::RecentScript::setBackground(const std::string &background) {
    background_ = background;
}

void ge::RecentScript::setScript(const std::queue<std::pair<std::wstring, std::wstring>> &script) {
    script_step_ = script;
}

void ge::RecentScript::emplaceBack(const std::pair<std::wstring, std::wstring> &step) {
    if (script_step_.size() == MAX_HISTORY_LENGTH) {
        script_step_.pop();
    }
    script_step_.push(step);
}

const std::wstring &ge::RecentScript::getTitle() const {
    return title_;
}

const std::string &ge::RecentScript::getBackground() const {
    return background_;
}

const std::queue<std::pair<std::wstring, std::wstring>> &ge::RecentScript::getScript() const {
    return script_step_;
}

bool ge::RecentScript::renderSfmlBasis(const sf::Vector2u &window_size) {
    if (is_rendered_) {
        return true;
    }
    sfml_basis_ = std::make_shared<RecentScriptSfmlBasis>();

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

    sf::Vector2f text_position = {
            text_background_position.x + text_background_size.x / 35.f,
            text_background_position.y + text_background_size.y / 8.f
    };
    sfml_basis_->script_step.resize(script_step_.size());
    for (std::pair<sf::Text, sf::Text>& step : sfml_basis_->script_step) {
        step.first.setFont(sfml_basis_->font);
        step.first.setCharacterSize(static_cast<unsigned int>(window_size.y * 0.02));
        step.first.setString((script_step_.front().first == ACTION ? L"\t" : script_step_.front().first + L":"));
        step.first.setFillColor(sf::Color::White);
        step.first.setOutlineColor(sf::Color::Black);
        step.first.setOutlineThickness(3);
        step.first.setPosition(text_position);

        text_position.x += 15;
        text_position.y += static_cast<float>(window_size.y) * 0.025f;

        step.second.setFont(sfml_basis_->font);
        step.second.setStyle(1 << 1);
        step.second.setCharacterSize(static_cast<unsigned int>(window_size.y * 0.02));
        step.second.setString(script_step_.front().second);
        step.second.setFillColor(sf::Color::White);
        step.second.setOutlineColor(sf::Color::Black);
        step.second.setOutlineThickness(2);
        step.second.setPosition(text_position);

        text_position.x -= 15;
        text_position.y += static_cast<float>(window_size.y) * 0.04f;
        script_step_.push(script_step_.front());
        script_step_.pop();
    }

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

void ge::RecentScript::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::RecentScript::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}