#include "scene_changes.h"

#include <unordered_map>

ge::SceneChanges::SceneChanges()
        : current_scene_(nullptr) {
}

ge::SceneChanges::SceneChanges(const std::shared_ptr<Scene> &scene)
        : current_scene_(scene) {
}

ge::SceneChanges::SceneChanges(const SceneChanges &scene_changes)
        : is_rendered_(scene_changes.is_rendered_), current_scene_(scene_changes.current_scene_),
          sfml_basic_(scene_changes.sfml_basic_) {
}

ge::SceneChanges::SceneChanges(SceneChanges &scene_changes)
        : is_rendered_(scene_changes.is_rendered_), current_scene_(scene_changes.current_scene_),
          sfml_basic_(scene_changes.sfml_basic_) {
}

ge::SceneChanges::SceneChanges(SceneChanges &&scene_changes) noexcept
        : is_rendered_(scene_changes.is_rendered_), current_scene_(std::move(scene_changes.current_scene_)),
          sfml_basic_(std::move(scene_changes.sfml_basic_)) {
}

ge::SceneChanges &ge::SceneChanges::operator=(const SceneChanges &scene_changes) {
    current_scene_ = scene_changes.current_scene_;
    sfml_basic_ = scene_changes.sfml_basic_;
    is_rendered_ = scene_changes.is_rendered_;
    return *this;
}

ge::SceneChanges &ge::SceneChanges::operator=(SceneChanges &&scene_changes) noexcept {
    current_scene_ = std::move(scene_changes.current_scene_);
    sfml_basic_ = std::move(scene_changes.sfml_basic_);
    is_rendered_ = scene_changes.is_rendered_;
    return *this;
}

void ge::SceneChanges::Update(const std::shared_ptr<Scene> &scene) const {
    if (!is_rendered_) {
        throw std::runtime_error("sfml_basic_ was not rendered\n");
    }
    if (scene->getBackgroundFile() != current_scene_->getBackgroundFile()) {
        sfml_basic_->background_texture_.loadFromFile(current_scene_->getBackgroundFile());
        sfml_basic_->background_sprite_.setTexture(sfml_basic_->background_texture_);
    }


    // TODO: перенос слотов
//    {
//        std::unordered_map<std::string, size_t> path_number_slot;
//        for (size_t number = 0; number < current_scene_->getSlots().getQuantityOfSlots(); ++number) {
//            path_number_slot[current_scene_->getSlots().getPicturesInSlots()[number]] = number;
//        }
//        if (scene->getSlots().getQuantityOfSlots() != current_scene_->getSlots().getQuantityOfSlots()) {
//            current_scene_->setSlots(scene->getSlots());
//        }
//        std::vector<sf::Sprite> actual_sprites(current_scene_->getSlots().getQuantityOfSlots());
//        for (size_t i = 0; i < current_scene_->getSlots().getQuantityOfSlots(); ++i) {
//            if (path_number_slot.find(current_scene_->getSlots().getPicturesInSlots()[i]) != path_number_slot.end()) {
//                actual_sprites[i] = sfml_basic_->slots_spites_[path_number_slot[current_scene_->getSlots().
//                        getPicturesInSlots()[i]]];
//
//            } else if (!current_scene_->getSlots().getPicturesInSlots()[i].empty()) {
//                sf::Texture slot_texture;
//                slot_texture.loadFromFile(current_scene_->getSlots().getPicturesInSlots()[i]);
//                actual_sprites[i].setTexture(slot_texture);
//            }
//        }
//        sfml_basic_->slots_spites_ = actual_sprites;
//    }

    if (scene->getDialogueBox() != current_scene_->getDialogueBox()) {
        sfml_basic_->replica_.setString(current_scene_->getDialogueBox().getReplica());
        sfml_basic_->speaker_.setString(current_scene_->getDialogueBox().getSpeaker());
    }

    if (scene->getActions() != current_scene_->getActions()) {
        const std::vector<Action> &new_actions = scene->getActions();
        sfml_basic_->action_buttons_.clear();
        sfml_basic_->action_buttons_.resize(new_actions.size());
        for (size_t i = 0; i < new_actions.size(); ++i) {
            sf::Text &action_button_i = sfml_basic_->action_buttons_[i];
            auto action_button_size = static_cast<unsigned int>(sfml_basic_->window_size_.y * 0.035);
            sf::Vector2f action_relative_coords = new_actions[i].getCoords();
            sf::Vector2f action_button_coords = {action_relative_coords.x *
                                                                           static_cast<float>(sfml_basic_->window_size_.x),
                                                 action_relative_coords.y *
                                                                           static_cast<float>(sfml_basic_->window_size_.y)};
            action_button_i.setPosition(action_button_coords);
            action_button_i.setFont(sfml_basic_->action_font_);
            action_button_i.setCharacterSize(action_button_size);
            action_button_i.setString(new_actions[i].getText());
            action_button_i.setFillColor(sf::Color::White);
            action_button_i.setOutlineColor(sf::Color::Black);
            action_button_i.setOutlineThickness(2);
        }
    }

    if (scene->getChoiceOfAction()) {
        sfml_basic_->replica_.setFillColor(sf::Color::Transparent);
        sfml_basic_->replica_.setOutlineColor(sf::Color::Transparent);
        sfml_basic_->speaker_.setFillColor(sf::Color::Transparent);
        sfml_basic_->speaker_.setOutlineColor(sf::Color::Transparent);
        sfml_basic_->replica_background_.setFillColor(sf::Color::Transparent);
        sfml_basic_->replica_background_.setOutlineColor(sf::Color::Transparent);
        sfml_basic_->speaker_background_.setFillColor(sf::Color::Transparent);
        sfml_basic_->speaker_background_.setOutlineColor(sf::Color::Transparent);
        for (sf::Text &action_button : sfml_basic_->action_buttons_) {
            action_button.setFillColor(sf::Color::White);
            action_button.setOutlineColor(sf::Color::Black);
        }
    } else if (!current_scene_->getChoiceOfAction()) {
        sfml_basic_->replica_.setFillColor(sf::Color::White);
        sfml_basic_->replica_.setOutlineColor(sf::Color::Black);
        sfml_basic_->speaker_.setFillColor(sf::Color::White);
        sfml_basic_->speaker_.setOutlineColor(sf::Color::Black);
        sfml_basic_->replica_background_.setFillColor(sf::Color::White);
        sfml_basic_->replica_background_.setOutlineColor(sf::Color::Black);
        sfml_basic_->speaker_background_.setFillColor(sf::Color::White);
        sfml_basic_->speaker_background_.setOutlineColor(sf::Color::Black);
        for (sf::Text &action_button : sfml_basic_->action_buttons_) {
            action_button.setFillColor(sf::Color::Transparent);
            action_button.setOutlineColor(sf::Color::Transparent);
        }
    }
}


void ge::SceneChanges::clearSfmlBasis() {
    sfml_basic_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::SceneChanges::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basic_);
}
