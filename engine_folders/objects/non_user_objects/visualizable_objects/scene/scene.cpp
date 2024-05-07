#include "scene.h"

#include <unordered_map>

ge::Scene::Scene()
        : current_frame_(nullptr) {
}

ge::Scene::Scene(const std::shared_ptr<Frame> &frame)
        : current_frame_(frame) {
}

ge::Scene::Scene(const Scene &scene)
        : is_rendered_(scene.is_rendered_), new_frame_is_processed(scene.new_frame_is_processed), current_frame_(scene.current_frame_), new_frame_(scene.new_frame_),
          sfml_basis_(scene.sfml_basis_) {
}

ge::Scene::Scene(Scene &scene)
        : is_rendered_(scene.is_rendered_), new_frame_is_processed(scene.new_frame_is_processed), current_frame_(scene.current_frame_), new_frame_(scene.new_frame_),
          sfml_basis_(scene.sfml_basis_) {
}

ge::Scene::Scene(Scene &&scene) noexcept
        : is_rendered_(scene.is_rendered_), new_frame_is_processed(scene.new_frame_is_processed), current_frame_(std::move(scene.current_frame_)), new_frame_(std::move(scene.new_frame_)),
          sfml_basis_(std::move(scene.sfml_basis_)) {
}

ge::Scene &ge::Scene::operator=(const Scene &scene) {
    current_frame_ = scene.current_frame_;
    new_frame_ = scene.new_frame_;
    sfml_basis_ = scene.sfml_basis_;
    is_rendered_ = scene.is_rendered_;
    new_frame_is_processed = scene.new_frame_is_processed;
    return *this;
}

ge::Scene &ge::Scene::operator=(Scene &&scene) noexcept {
    current_frame_ = std::move(scene.current_frame_);
    new_frame_ = std::move(scene.new_frame_);
    sfml_basis_ = std::move(scene.sfml_basis_);
    is_rendered_ = scene.is_rendered_;
    new_frame_is_processed = scene.new_frame_is_processed;
    return *this;
}

void ge::Scene::setNewFrame(const std::shared_ptr<Frame> &frame) {
    new_frame_ = frame;
    new_frame_is_processed = false;
}

void ge::Scene::processNewFrame() {
    if (!is_rendered_) {
        throw std::runtime_error("sfml_basis_ was not rendered\n");
    }
    if (new_frame_ == nullptr) {
        throw std::runtime_error("new_frame_ was not set\n");
    }
    if (new_frame_->getBackgroundFile() != current_frame_->getBackgroundFile()) {
        sfml_basis_->background_texture_.loadFromFile(current_frame_->getBackgroundFile());
        sfml_basis_->background_sprite_.setTexture(sfml_basis_->background_texture_);
    }


    // TODO: перенос слотов
//    {
//        std::unordered_map<std::string, size_t> path_number_slot;
//        for (size_t number = 0; number < current_scene_->getSlots().getQuantityOfSlots(); ++number) {
//            path_number_slot[current_scene_->getSlots().getPicturesInSlots()[number]] = number;
//        }
//        if (new_frame_->getSlots().getQuantityOfSlots() != current_scene_->getSlots().getQuantityOfSlots()) {
//            current_scene_->setSlots(new_frame_->getSlots());
//        }
//        std::vector<sf::Sprite> actual_sprites(current_scene_->getSlots().getQuantityOfSlots());
//        for (size_t i = 0; i < current_scene_->getSlots().getQuantityOfSlots(); ++i) {
//            if (path_number_slot.find(current_scene_->getSlots().getPicturesInSlots()[i]) != path_number_slot.end()) {
//                actual_sprites[i] = sfml_basis_->slots_spites_[path_number_slot[current_scene_->getSlots().
//                        getPicturesInSlots()[i]]];
//
//            } else if (!current_scene_->getSlots().getPicturesInSlots()[i].empty()) {
//                sf::Texture slot_texture;
//                slot_texture.loadFromFile(current_scene_->getSlots().getPicturesInSlots()[i]);
//                actual_sprites[i].setTexture(slot_texture);
//            }
//        }
//        sfml_basis_->slots_spites_ = actual_sprites;
//    }

    if (new_frame_->getDialogueBox() != current_frame_->getDialogueBox()) {
        sfml_basis_->replica_.setString(current_frame_->getDialogueBox().getReplica());
        sfml_basis_->speaker_.setString(current_frame_->getDialogueBox().getSpeaker());
    }

    if (new_frame_->getActions() != current_frame_->getActions()) {
        const std::vector<Action> &new_actions = new_frame_->getActions();
        sfml_basis_->action_buttons_.clear();
        sfml_basis_->action_buttons_.resize(new_actions.size());
        for (size_t i = 0; i < new_actions.size(); ++i) {
            sf::Text &action_button_i = sfml_basis_->action_buttons_[i];
            auto action_button_size = static_cast<unsigned int>(sfml_basis_->window_size_.y * 0.035);
            sf::Vector2f action_relative_coords = new_actions[i].getCoords();
            sf::Vector2f action_button_coords = {action_relative_coords.x *
                                                 static_cast<float>(sfml_basis_->window_size_.x),
                                                 action_relative_coords.y *
                                                 static_cast<float>(sfml_basis_->window_size_.y)};
            action_button_i.setPosition(action_button_coords);
            action_button_i.setFont(sfml_basis_->font_);
            action_button_i.setCharacterSize(action_button_size);
            action_button_i.setString(new_actions[i].getText());
            action_button_i.setFillColor(sf::Color::White);
            action_button_i.setOutlineColor(sf::Color::Black);
            action_button_i.setOutlineThickness(2);
        }
    }

    if (new_frame_->getChoiceOfAction()) {
        sfml_basis_->replica_.setFillColor(sf::Color::Transparent);
        sfml_basis_->replica_.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->speaker_.setFillColor(sf::Color::Transparent);
        sfml_basis_->speaker_.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->replica_background_.setFillColor(sf::Color::Transparent);
        sfml_basis_->replica_background_.setOutlineColor(sf::Color::Transparent);
        sfml_basis_->speaker_background_.setFillColor(sf::Color::Transparent);
        sfml_basis_->speaker_background_.setOutlineColor(sf::Color::Transparent);
        for (sf::Text &action_button: sfml_basis_->action_buttons_) {
            action_button.setFillColor(sf::Color::White);
            action_button.setOutlineColor(sf::Color::Black);
        }
    } else if (!current_frame_->getChoiceOfAction()) {
        sfml_basis_->replica_.setFillColor(sf::Color::White);
        sfml_basis_->replica_.setOutlineColor(sf::Color::Black);
        sfml_basis_->speaker_.setFillColor(sf::Color::White);
        sfml_basis_->speaker_.setOutlineColor(sf::Color::Black);
        sfml_basis_->replica_background_.setFillColor(sf::Color::White);
        sfml_basis_->replica_background_.setOutlineColor(sf::Color::Black);
        sfml_basis_->speaker_background_.setFillColor(sf::Color::White);
        sfml_basis_->speaker_background_.setOutlineColor(sf::Color::Black);
        for (sf::Text &action_button: sfml_basis_->action_buttons_) {
            action_button.setFillColor(sf::Color::Transparent);
            action_button.setOutlineColor(sf::Color::Transparent);
        }
    }
    current_frame_ = new_frame_;
    new_frame_ = nullptr;
    new_frame_is_processed = true;
}

bool ge::Scene::renderSfmlBasis(const sf::Vector2u &window_size) {
    if (is_rendered_ && new_frame_is_processed) {
        return true;
    }
    if (is_rendered_ && !new_frame_is_processed) {\
        processNewFrame();
        return true;
    }

    sfml_basis_ = std::make_shared<SceneSfmlBasis>();
    // setting background
    if (!sfml_basis_->background_texture_.loadFromFile(new_frame_->getBackgroundFile())) {
        return false;
    }
    sfml_basis_->background_sprite_.setTexture(sfml_basis_->background_texture_);
    sfml_basis_->background_sprite_.scale({
                                                  static_cast<float>(window_size.x) / 3840.0f,
                                                  static_cast<float>(window_size.y) / 2160.0f
                                          });
    // setting slot pictures
    sfml_basis_->font_.loadFromFile(FONT_NAME);
    size_t slots_quantity = new_frame_->getSlots().getQuantityOfSlots();
    unsigned int distance_between_slots = window_size.x / (slots_quantity + 1);

    const std::vector<std::string> &pictures_in_slots = new_frame_->getSlots().getPicturesInSlots();
    sfml_basis_->slots_textures_.resize(slots_quantity);
    sfml_basis_->slots_spites_.resize(slots_quantity);
    for (size_t i = 0; i < slots_quantity; ++i) {
        sfml_basis_->slots_textures_[i].loadFromFile(pictures_in_slots[i]);
        sfml_basis_->slots_spites_[i].setTexture(sfml_basis_->slots_textures_[i]);
        sf::Vector2f slot_coords = {};
    }

    return true;
}

void ge::Scene::clearSfmlBasis() {
    sfml_basis_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::Scene::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basis_);
}

