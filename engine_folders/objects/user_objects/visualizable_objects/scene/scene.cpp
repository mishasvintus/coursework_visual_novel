#include "scene.h"

#include <utility>

void checkingCorrectness(const std::string &path) {
    sf::Image image;
    if (image.loadFromFile(path)) {
        throw std::runtime_error("file or file's path is incorrect\n");
    }
}

ge::Scene::Scene(const Scene &scene)
    : dialogue_box_(scene.dialogue_box_), background_file_(scene.background_file_),
      choice_of_action_(scene.choice_of_action_), actions_(scene.actions_), scene_slots_(scene.scene_slots_) {
}

ge::Scene::Scene(DialogueBox dialogue_box, std::string background_file, bool choice_of_action,
                 const std::vector<Action> &actions, SceneSlots scene_slots)
    : dialogue_box_(std::move(dialogue_box)), background_file_(std::move(background_file)),
      choice_of_action_(choice_of_action), actions_(actions), scene_slots_(std::move(scene_slots)) {
    checkingCorrectness(background_file);
}

ge::Scene::Scene(Scene &scene)
    : dialogue_box_(scene.dialogue_box_), background_file_(scene.background_file_),
      choice_of_action_(scene.choice_of_action_), actions_(scene.actions_), scene_slots_(scene.scene_slots_) {
}

ge::Scene::Scene(Scene &&scene) noexcept
    : dialogue_box_(std::move(scene.dialogue_box_)), background_file_(std::move(scene.background_file_)),
      choice_of_action_(scene.choice_of_action_), actions_(std::move(scene.actions_)),
      scene_slots_(std::move(scene.scene_slots_)) {
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

void ge::Scene::setDialogueBox(const DialogueBox &dialogue_box) {
    dialogue_box_ = dialogue_box;
}

void ge::Scene::setBackgroundFile(const std::string &background_file) {
    checkingCorrectness(background_file);
    background_file_ = background_file;
}

void ge::Scene::setChoiceOfAction(bool choice_of_action) {
    choice_of_action_ = choice_of_action; ///TODO: пусть будет так, а вообще всегда возвращаем true по идее
}

void ge::Scene::setActions(const std::vector<Action> &actions) {
    actions_ = actions;
}

void ge::Scene::setSlots(const SceneSlots &scene_slots) {
    scene_slots_ = scene_slots;
}

const ge::DialogueBox &ge::Scene::getDialogueBox() {
    return dialogue_box_;
}

const std::string &ge::Scene::getBackgroundFile() const {
    return background_file_;
}

bool ge::Scene::getChoiceOfAction() const {
    return choice_of_action_;
}

const std::vector<ge::Action> &ge::Scene::getActions() const {
    return actions_;
}

const ge::SceneSlots &ge::Scene::getSlots() const {
    return scene_slots_;
}
