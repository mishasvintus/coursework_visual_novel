#include "scene.h"

#include <utility>

ge::Scene::Scene(const Scene &scene)
    : dialogue_box_(scene.dialogue_box_)
      , background_file_(scene.background_file_)
      , choice_of_action_(scene.choice_of_action_)
      , actions_(scene.actions_)
      , scene_slots_(scene.scene_slots_) {
}

ge::Scene::Scene(DialogueBox dialogue_box, std::string background_file, bool choice_of_action,
                 const std::vector<Action> &actions, SceneSlots scene_slots)
    : dialogue_box_(std::move(dialogue_box))
      , background_file_(std::move(background_file))
      , choice_of_action_(choice_of_action)
      , actions_(actions)
      , scene_slots_(std::move(scene_slots)) {
}

ge::Scene::Scene(Scene &scene)
    : dialogue_box_(scene.dialogue_box_)
    , background_file_(scene.background_file_)
    , choice_of_action_(scene.choice_of_action_)
    , actions_(scene.actions_)
    , scene_slots_(scene.scene_slots_) {
}

ge::Scene::Scene(Scene &&scene) noexcept
    : dialogue_box_(std::move(scene.dialogue_box_))
    , background_file_(std::move(scene.background_file_))
    , choice_of_action_(scene.choice_of_action_)
    , actions_(std::move(scene.actions_))
    , scene_slots_(std::move(scene.scene_slots_)) {
}

ge::Scene &ge::Scene::operator=(const Scene &scene) {
    dialogue_box_ = scene.dialogue_box_;
    background_file_ = scene.background_file_;
    choice_of_action_ = scene.choice_of_action_;
    actions_ = scene.actions_;
    scene_slots_ = scene.scene_slots_;
    return *this;
}

ge::Scene &ge::Scene::operator=(Scene &&scene) noexcept {
    dialogue_box_ = std::move(scene.dialogue_box_);
    background_file_ = std::move(scene.background_file_);
    choice_of_action_ = scene.choice_of_action_;
    actions_ = std::move(scene.actions_);
    scene_slots_ = std::move(scene.scene_slots_);
    return *this;
}

bool ge::Scene::setDialogueBox(const DialogueBox &dialogue_box) {
    try {
        dialogue_box_ = dialogue_box;
    } catch (...) {
        return false; ///TODO: пусть будет так, а вообще всегда возвращаем true по идее
    }
    return true;
}

bool ge::Scene::setBackgroundFile(const std::string &background_file) {
    try {
        background_file_ = background_file;
        // TODO: парс файла по-хорошему надо прописать
    } catch (...) {
        return false;
    }
    return true;
}

bool ge::Scene::setChoiceOfAction(bool choice_of_action) {
    try {
        choice_of_action_ = choice_of_action; ///TODO: пусть будет так, а вообще всегда возвращаем true по идее
    } catch (...) {
        return false;
    }
    return true;
}

bool ge::Scene::setActions(const std::vector<Action> &actions) {
    try {
        actions_ = actions;
    } catch (...) {
        return false;
    }
    return true;
}

bool ge::Scene::setSlots(const SceneSlots &scene_slots) {
    try {
        scene_slots_ = scene_slots;
    } catch (...) {
        return false;
    }
    return true;
}

std::shared_ptr<ge::DialogueBox> ge::Scene::getDialogueBox() {
    return std::make_shared<DialogueBox>(dialogue_box_);
}

std::string ge::Scene::getBackgroundFile() {
    return background_file_;
}

bool ge::Scene::getChoiceOfAction() const {
    return choice_of_action_;
}

std::vector<ge::Action> ge::Scene::getActions() {
    return actions_; // TODO: может тоже указатели лучше использовать

}

ge::SceneSlots ge::Scene::getSlots() {
    return scene_slots_; // TODO: может тоже указатели лучше использовать

}
