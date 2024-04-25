#include "scene_changes.h"

#include <unordered_map>

ge::SceneChanges::SceneChanges()
    : actual_cadr_(std::make_shared<Scene>()) {
}

ge::SceneChanges::SceneChanges(const std::shared_ptr<Scene> &scene)
    : actual_cadr_(std::make_shared<Scene>()) {
    actual_cadr_->setActions(scene->getActions());
    actual_cadr_->setSlots(scene->getSlots());
    actual_cadr_->setBackgroundFile(scene->getBackgroundFile());
    actual_cadr_->setDialogueBox(scene->getDialogueBox());
    actual_cadr_->setChoiceOfAction(scene->getChoiceOfAction());
}

ge::SceneChanges::SceneChanges(const SceneChanges &scene_changes)
    : is_rendered_(scene_changes.is_rendered_)
      , actual_cadr_(scene_changes.actual_cadr_)
      , sfml_basic_(scene_changes.sfml_basic_) {
}

ge::SceneChanges::SceneChanges(SceneChanges &scene_changes)
    : is_rendered_(scene_changes.is_rendered_)
      , actual_cadr_(scene_changes.actual_cadr_)
      , sfml_basic_(scene_changes.sfml_basic_) {
}

ge::SceneChanges::SceneChanges(SceneChanges &&scene_changes) noexcept
    : is_rendered_(scene_changes.is_rendered_)
      , actual_cadr_(std::move(scene_changes.actual_cadr_))
      , sfml_basic_(std::move(scene_changes.sfml_basic_)) {
}

ge::SceneChanges &ge::SceneChanges::operator=(const SceneChanges &scene_changes) {
    actual_cadr_ = scene_changes.actual_cadr_;
    sfml_basic_ = scene_changes.sfml_basic_;
    is_rendered_ = scene_changes.is_rendered_;
    return *this;
}

ge::SceneChanges &ge::SceneChanges::operator=(SceneChanges &&scene_changes) noexcept {
    actual_cadr_ = std::move(scene_changes.actual_cadr_);
    sfml_basic_ = std::move(scene_changes.sfml_basic_);
    is_rendered_ = scene_changes.is_rendered_;
    return *this;
}

void ge::SceneChanges::Update(const std::shared_ptr<Scene> &scene) const {
    if (!sfml_basic_) {
        throw std::runtime_error("sfml_basic_ was not rendered\n");
    }
    if (scene->getBackgroundFile() != actual_cadr_->getBackgroundFile()) {
        actual_cadr_->setBackgroundFile(scene->getBackgroundFile());
        sf::Texture background_texture;
        background_texture.loadFromFile(actual_cadr_->getBackgroundFile());
        sfml_basic_->background_sprite_.setTexture(background_texture);
    }

    {
        std::unordered_map<std::string, size_t> path_number_slot;
        for (size_t number = 0; number < actual_cadr_->getSlots().getQuantityOfSlots(); ++number) {
            path_number_slot[actual_cadr_->getSlots().getPicturesInSlots()[number]] = number;
        }
        if (scene->getSlots().getQuantityOfSlots() != actual_cadr_->getSlots().getQuantityOfSlots()) {
            actual_cadr_->setSlots(scene->getSlots());
        }
        std::vector<sf::Sprite> actual_sprites(actual_cadr_->getSlots().getQuantityOfSlots());
        for (size_t i = 0; i < actual_cadr_->getSlots().getQuantityOfSlots(); ++i) {
            if (path_number_slot.find(actual_cadr_->getSlots().getPicturesInSlots()[i]) != path_number_slot.end()) {
                actual_sprites[i] = sfml_basic_->slots_spites_[path_number_slot[actual_cadr_->getSlots().
                    getPicturesInSlots()[i]]];

            } else if (!actual_cadr_->getSlots().getPicturesInSlots()[i].empty()) {
                sf::Texture slot_texture;
                slot_texture.loadFromFile(actual_cadr_->getSlots().getPicturesInSlots()[i]);
                actual_sprites[i].setTexture(slot_texture);
            }
        }
        sfml_basic_->slots_spites_ = actual_sprites;
    }

    actual_cadr_->setDialogueBox(scene->getDialogueBox());
    sfml_basic_->replica_.setString(actual_cadr_->getDialogueBox().getReplica());
    sfml_basic_->speaker_.setString(actual_cadr_->getDialogueBox().getSpeaker());

    actual_cadr_->setChoiceOfAction(scene->getChoiceOfAction());
    actual_cadr_->setActions(scene->getActions());
    sfml_basic_->buttons_.resize(actual_cadr_->getActions().size());
    for (size_t i = 0; i < sfml_basic_->buttons_.size(); ++i) {
        sfml_basic_->buttons_[i].setString(actual_cadr_->getActions()[i].getText());
    }
}


void ge::SceneChanges::clearSfmlBasis() {
    sfml_basic_.reset();
    is_rendered_ = false;
}

std::shared_ptr<ge::SfmlBasis> ge::SceneChanges::getSfmlBasis() {
    return std::static_pointer_cast<SfmlBasis>(sfml_basic_);
}
