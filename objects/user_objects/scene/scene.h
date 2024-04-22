#pragma once

#include <string>
#include "dialogue_box.h"
#include "object.h"
#include "actions.h"

namespace ge {
    class Scene : Object {
        Scene();
        Scene(const Scene& scene);
        Scene(Scene& scene);
        Scene(Scene&& scene);
        Scene(DialogueBox& dialogue_box, std::string& background_file, bool choice_of_action, std::vector<Action>& actions);
        ~Scene() = default;


    private:
        DialogueBox _dialogue_box;
        std::string _background_file;
        bool _choice_of_action;
        std::vector<Action> _actions;
        std::vector<sf::Sprite> getSpriteVector(sf::Vector2i window_size) override;
    };
}
