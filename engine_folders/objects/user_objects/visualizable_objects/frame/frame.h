#pragma once

#include "actions.h"
#include "dialogue_box.h"
#include "visualizable.h"
#include "frame_slots.h"

#include <string>

namespace ge {
    class Frame : Visualizable {
    public:
        Frame() = default;

        Frame(const Frame &scene);

        Frame(Frame &scene);

        Frame(Frame &&scene) noexcept;

        Frame(DialogueBox dialogue_box, std::string background_file, bool choice_of_action,
              const std::vector<Action> &actions, FrameSlots scene_slots);

        ~Frame() override = default;

        Frame &operator=(const Frame &scene);

        Frame &operator=(Frame &&scene) noexcept;

        void setDialogueBox(const DialogueBox &dialogue_box);

        void setBackgroundFile(const std::string &background_file);

        void setChoiceOfAction(bool choice_of_action);

        void setActions(const std::vector<Action> &actions);

        void setSlots(const FrameSlots &scene_slots);

        const DialogueBox &getDialogueBox() const;

        [[nodiscard]] const std::string &getBackgroundFile() const;

        [[nodiscard]] bool getChoiceOfAction() const;

        [[nodiscard]] const std::vector<Action> &getActions() const;

        [[nodiscard]] const FrameSlots &getSlots() const;

    private:
        bool renderSfmlBasis(const sf::Vector2u &window_size) override {
            return true; /// TODO: реализовать
        }

        void clearSfmlBasis() override {
            /// TODO: реализовать
        }

        std::shared_ptr<SfmlBasis> getSfmlBasis() override {
            return {}; /// TODO: реализовать
        }

        DialogueBox dialogue_box_;
        std::string background_file_;
        bool choice_of_action_ = false;
        std::vector<Action> actions_;
        FrameSlots scene_slots_;
    };
}
