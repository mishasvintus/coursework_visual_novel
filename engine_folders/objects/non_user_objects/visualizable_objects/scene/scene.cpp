#include "scene.h"

#include <unordered_map>

ge::Scene::Scene()
        : current_frame_(nullptr) {
}

ge::Scene::Scene(const std::shared_ptr<Frame> &frame)
        : current_frame_(frame) {
}

ge::Scene::Scene(const Scene &scene)
        : is_rendered_(scene.is_rendered_), current_frame_(scene.current_frame_),
          sfml_basic_(scene.sfml_basic_) {
}

ge::Scene::Scene(Scene &scene)
        : is_rendered_(scene.is_rendered_), current_frame_(scene.current_frame_),
          sfml_basic_(scene.sfml_basic_) {
}

ge::Scene::Scene(Scene &&scene) noexcept
        : is_rendered_(scene.is_rendered_), current_frame_(std::move(scene.current_frame_)),
          sfml_basic_(std::move(scene.sfml_basic_)) {
}

ge::Scene &ge::Scene::operator=(const Scene &scene) {
    current_frame_ = scene.current_frame_;
    sfml_basic_ = scene.sfml_basic_;
    is_rendered_ = scene.is_rendered_;
    return *this;
}

ge::Scene &ge::Scene::operator=(Scene &&scene) noexcept {
    current_frame_ = std::move(scene.current_frame_);
    sfml_basic_ = std::move(scene.sfml_basic_);
    is_rendered_ = scene.is_rendered_;
    return *this;
}

void ge::Scene::Update(const std::shared_ptr<Frame> &frame) const {
    if (!is_rendered_) {
        throw std::runtime_error("sfml_basic_ was not rendered\n");
    }
    if (frame->getBackgroundFile() != current_frame_->getBackgroundFile()) {
        sfml_basic_->background_texture_.loadFromFile(current_frame_->getBackgroundFile());
        sfml_basic_->background_sprite_.setTexture(sfml_basic_->background_texture_);
    }


    // TODO: перенос слотов
//    {
//        std::unordered_map<std::string, size_t> path_number_slot;
//        for (size_t number = 0; number < current_scene_->getSlots().getQuantityOfSlots(); ++number) {
//            path_number_slot[current_scene_->getSlots().getPicturesInSlots()[number]] = number;
//        }
//        if (frame->getSlots().getQuantityOfSlots() != current_scene_->getSlots().getQuantityOfSlots()) {
//            current_scene_->setSlots(frame->getSlots());
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

    if (frame->getDialogueBox() != current_frame_->getDialogueBox()) {
        sfml_basic_->replica_.setString(current_frame_->getDialogueBox().getReplica());
        sfml_basic_->speaker_.setString(current_frame_->getDialogueBox().getSpeaker());
    }

    if (frame->getActions() != current_frame_->getActions()) {
        const std::vector<Action> &new_actions = frame->getActions();
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

    if (frame->getChoiceOfAction()) {
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
    } else if (!current_frame_->getChoiceOfAction()) {
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

bool ge::Scene::renderSfmlBasis(const sf::Vector2u &window_size) {
    // TODO: todo
    return true;
}

void ge::Scene::clearSfmlBasis() {
    sfml_basic_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::Scene::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basic_);
}

