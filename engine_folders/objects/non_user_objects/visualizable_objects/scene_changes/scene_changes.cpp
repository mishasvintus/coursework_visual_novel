#include "scene_changes.h"

ge::SceneChanges::SceneChanges()
    : actual_cadr_(std::make_shared<Scene>()){
}

ge::SceneChanges::SceneChanges(const std::shared_ptr<Scene> &scene)
    : actual_cadr_(std::make_shared<Scene>())
      , past_scene_(scene) {
    actual_cadr_->setActions(scene->getActions());
    actual_cadr_->setSlots(scene->getSlots());
    actual_cadr_->setBackgroundFile(scene->getBackgroundFile());
    actual_cadr_->setDialogueBox(scene->getDialogueBox());
    actual_cadr_->setChoiceOfAction(scene->getChoiceOfAction());
}

ge::SceneChanges::SceneChanges(const SceneChanges &scene_changes)
    : actual_cadr_(scene_changes.actual_cadr_)
      , past_scene_(scene_changes.past_scene_)
      , sfml_basic_(scene_changes.sfml_basic_) {
}

ge::SceneChanges::SceneChanges(SceneChanges &scene_changes)
    : actual_cadr_(scene_changes.actual_cadr_)
      , past_scene_(scene_changes.past_scene_)
      , sfml_basic_(scene_changes.sfml_basic_) {
}

ge::SceneChanges::SceneChanges(SceneChanges &&scene_changes) noexcept
    : actual_cadr_(std::move(scene_changes.actual_cadr_))
    , past_scene_(std::move(scene_changes.past_scene_))
    , sfml_basic_(std::move(scene_changes.sfml_basic_)) {
}

ge::SceneChanges &ge::SceneChanges::operator=(const SceneChanges &scene_changes) {
    actual_cadr_ = scene_changes.actual_cadr_;
    past_scene_ = scene_changes.past_scene_;
    sfml_basic_ = scene_changes.sfml_basic_;
    return *this;
}

ge::SceneChanges &ge::SceneChanges::operator=(SceneChanges &&scene_changes) noexcept {
    actual_cadr_ = std::move(scene_changes.actual_cadr_);
    past_scene_ = std::move(scene_changes.past_scene_);
    sfml_basic_ = std::move(scene_changes.sfml_basic_);
    return *this;
}