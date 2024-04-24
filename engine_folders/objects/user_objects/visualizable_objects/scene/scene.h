#pragma once

#include "actions.h"
#include "dialogue_box.h"
#include "visualizable.h"
#include "scene_slots.h"

#include <string>

namespace ge {
    class Scene : Visualizable {
    public:
        Scene() = default;

        Scene(const Scene &scene);

        Scene(Scene &scene);

        Scene(Scene &&scene) noexcept;

        Scene(DialogueBox dialogue_box, std::string background_file, bool choice_of_action,
              const std::vector<Action> &actions, SceneSlots scene_slots);

        ~Scene() override = default;

        Scene &operator=(const Scene &scene);

        Scene &operator=(Scene &&scene) noexcept;

        bool setDialogueBox(const DialogueBox &dialogue_box);

        bool setBackgroundFile(const std::string &background_file);

        bool setChoiceOfAction(bool choice_of_action);

        bool setActions(const std::vector<Action> &actions);

        bool setSlots(const SceneSlots &scene_slots);

        const DialogueBox &getDialogueBox();

        [[nodiscard]] const std::string &getBackgroundFile() const;

        [[nodiscard]] bool getChoiceOfAction() const;

        [[nodiscard]] const std::vector<Action> &getActions() const;

        [[nodiscard]] const SceneSlots &getSlots() const;

    private:
        bool render(const sf::Vector2u &window_size) override {
            return true; /// TODO: реализовать
        }

        void clearDrawables() override {
            /// TODO: реализовать
        }

        std::vector<std::shared_ptr<sf::Drawable>> getDrawables() override {
            return {}; /// TODO: реализовать
        }

        DialogueBox dialogue_box_;
        std::string background_file_;
        bool choice_of_action_ = false;
        std::vector<Action> actions_;
        SceneSlots scene_slots_;
    };
}
