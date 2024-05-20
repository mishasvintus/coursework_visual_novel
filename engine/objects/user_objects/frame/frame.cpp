#include "frame.h"

#include <utility>

void checkingCorrectness(const std::string &path) {
    sf::Image image;
    if (!image.loadFromFile(path)) {
        throw std::runtime_error("file or file's path is incorrect\n");
    }
}

ge::Frame::Frame(const Frame &scene)
        : dialogue_box_(scene.dialogue_box_), background_file_(scene.background_file_),
          choice_of_action_(scene.choice_of_action_), actions_(scene.actions_), scene_slots_(scene.scene_slots_) {
}

ge::Frame::Frame(ge::DialogueBox dialogue_box, std::string background_file, ge::FrameSlots slots)
        : dialogue_box_(std::move(dialogue_box)), background_file_(std::move(background_file)),
          scene_slots_(std::move(slots)) {
}

ge::Frame::Frame(const std::vector<Action> &actions, std::string background_file, ge::FrameSlots slots)
        : actions_(actions), background_file_(std::move(background_file)), scene_slots_(std::move(slots)),
          choice_of_action_(true) {
}

ge::Frame::Frame(Frame &scene)
        : dialogue_box_(scene.dialogue_box_), background_file_(scene.background_file_),
          choice_of_action_(scene.choice_of_action_), actions_(scene.actions_), scene_slots_(scene.scene_slots_) {
}

ge::Frame::Frame(Frame &&scene) noexcept
        : dialogue_box_(std::move(scene.dialogue_box_)), background_file_(std::move(scene.background_file_)),
          choice_of_action_(scene.choice_of_action_), actions_(std::move(scene.actions_)),
          scene_slots_(std::move(scene.scene_slots_)) {
}

ge::Frame &ge::Frame::operator=(const Frame &scene) {
    dialogue_box_ = scene.dialogue_box_;
    background_file_ = scene.background_file_;
    choice_of_action_ = scene.choice_of_action_;
    actions_ = scene.actions_;
    scene_slots_ = scene.scene_slots_;
    return *this;
}

ge::Frame &ge::Frame::operator=(Frame &&scene) noexcept {
    dialogue_box_ = std::move(scene.dialogue_box_);
    background_file_ = std::move(scene.background_file_);
    choice_of_action_ = scene.choice_of_action_;
    actions_ = std::move(scene.actions_);
    scene_slots_ = std::move(scene.scene_slots_);
    return *this;
}

void ge::Frame::setDialogueBox(const DialogueBox &dialogue_box) {
    dialogue_box_ = dialogue_box;
}

void ge::Frame::setBackgroundFile(const std::string &background_file) {
    checkingCorrectness(background_file);
    background_file_ = background_file;
}

void ge::Frame::setChoiceOfAction(bool choice_of_action) {
    choice_of_action_ = choice_of_action; ///TODO: пусть будет так, а вообще всегда возвращаем true по идее
}

void ge::Frame::setActions(const std::vector<Action> &actions) {
    actions_ = actions;
}

void ge::Frame::setSlots(const FrameSlots &scene_slots) {
    scene_slots_ = scene_slots;
}

const ge::DialogueBox &ge::Frame::getDialogueBox() const {
    return dialogue_box_;
}

const std::string &ge::Frame::getBackgroundFile() const {
    return background_file_;
}

bool ge::Frame::getChoiceOfAction() const {
    return choice_of_action_;
}

const std::vector<ge::Action> &ge::Frame::getActions() const {
    return actions_;
}

const ge::FrameSlots &ge::Frame::getSlots() const {
    return scene_slots_;
}