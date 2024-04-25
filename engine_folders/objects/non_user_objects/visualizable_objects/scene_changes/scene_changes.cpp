#include "scene_changes.h"

#include <unordered_map>

ge::SceneChanges::SceneChanges()
    : current_scene_(std::make_shared<Scene>()) {
}

ge::SceneChanges::SceneChanges(const std::shared_ptr<Scene> &scene)
    : current_scene_(std::make_shared<Scene>()) {
    current_scene_->setActions(scene->getActions());
    current_scene_->setSlots(scene->getSlots());
    current_scene_->setBackgroundFile(scene->getBackgroundFile());
    current_scene_->setDialogueBox(scene->getDialogueBox());
    current_scene_->setChoiceOfAction(scene->getChoiceOfAction());
}

ge::SceneChanges::SceneChanges(const SceneChanges &scene_changes)
    : is_rendered_(scene_changes.is_rendered_)
      , current_scene_(scene_changes.current_scene_)
      , sfml_basic_(scene_changes.sfml_basic_) {
}

ge::SceneChanges::SceneChanges(SceneChanges &scene_changes)
    : is_rendered_(scene_changes.is_rendered_)
      , current_scene_(scene_changes.current_scene_)
      , sfml_basic_(scene_changes.sfml_basic_) {
}

ge::SceneChanges::SceneChanges(SceneChanges &&scene_changes) noexcept
    : is_rendered_(scene_changes.is_rendered_)
      , current_scene_(std::move(scene_changes.current_scene_))
      , sfml_basic_(std::move(scene_changes.sfml_basic_)) {
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
        current_scene_->setBackgroundFile(scene->getBackgroundFile());
        sf::Texture background_texture;
        background_texture.loadFromFile(current_scene_->getBackgroundFile());
        sfml_basic_->background_sprite_.setTexture(background_texture);
    }

    {
        std::unordered_map<std::string, size_t> path_number_slot;
        for (size_t number = 0; number < current_scene_->getSlots().getQuantityOfSlots(); ++number) {
            path_number_slot[current_scene_->getSlots().getPicturesInSlots()[number]] = number;
        }
        if (scene->getSlots().getQuantityOfSlots() != current_scene_->getSlots().getQuantityOfSlots()) {
            current_scene_->setSlots(scene->getSlots());
        }
        std::vector<sf::Sprite> actual_sprites(current_scene_->getSlots().getQuantityOfSlots());
        for (size_t i = 0; i < current_scene_->getSlots().getQuantityOfSlots(); ++i) {
            if (path_number_slot.find(current_scene_->getSlots().getPicturesInSlots()[i]) != path_number_slot.end()) {
                actual_sprites[i] = sfml_basic_->slots_spites_[path_number_slot[current_scene_->getSlots().
                    getPicturesInSlots()[i]]];

            } else if (!current_scene_->getSlots().getPicturesInSlots()[i].empty()) {
                sf::Texture slot_texture;
                slot_texture.loadFromFile(current_scene_->getSlots().getPicturesInSlots()[i]);
                actual_sprites[i].setTexture(slot_texture);
            }
        }
        sfml_basic_->slots_spites_ = actual_sprites;
    }

    current_scene_->setDialogueBox(scene->getDialogueBox());
    sfml_basic_->replica_.setString(current_scene_->getDialogueBox().getReplica());
    sfml_basic_->speaker_.setString(current_scene_->getDialogueBox().getSpeaker());

    current_scene_->setChoiceOfAction(scene->getChoiceOfAction());
    current_scene_->setActions(scene->getActions());
    sfml_basic_->buttons_.resize(current_scene_->getActions().size());
    for (size_t i = 0; i < sfml_basic_->buttons_.size(); ++i) {
        sfml_basic_->buttons_[i].setString(current_scene_->getActions()[i].getText());
    }
}


void ge::SceneChanges::clearSfmlBasis() {
    sfml_basic_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::SceneChanges::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basic_);
}
