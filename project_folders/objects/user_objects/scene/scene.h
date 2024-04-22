#pragma once

#include <string>
#include "dialogue_box.h"
#include "object.h"
#include "actions.h"
#include "scene_slots.h"

namespace ge {
    class Scene : Object {
    public:
        Scene();

        Scene(const Scene &scene);

        Scene(Scene &scene);

        Scene(Scene &&scene) noexcept;

        Scene(const DialogueBox &dialogue_box, const std::string &background_file, bool choice_of_action,
              const std::vector<Action> &actions, const SceneSlots &scene_slots);

        ~Scene() override = default;

        bool setDialogueBox(const DialogueBox& dialogueBox);

        bool setBackgroundFile(const std::string& background_file);

        bool setChoiceOfAction(bool choice_of_action);

        bool setActions(const std::vector<Action>& actions);

        bool setSlots(const SceneSlots& scene_slot);

        DialogueBox getDialogueBox();

        std::string getBackgroundFile();

        bool getChoiceOfAction();

        std::vector<Action> getActions();

        SceneSlots getSlots();

    private:
        DialogueBox dialogue_box_;
        std::string background_file_;
        bool choice_of_action_;
        std::vector<Action> actions_;
        SceneSlots scene_slots_;

        std::vector<sf::Sprite> getSpriteVector(const sf::Vector2i& window_size) override;
    };




}
