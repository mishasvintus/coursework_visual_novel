#pragma once

#include <string>
#include "dialogue_box.h"
#include "object.h"
#include "actions.h"

namespace ge {
    class Scene : Object {
    public:
        Scene();

        Scene(const Scene &scene);

        Scene(Scene &scene);

        Scene(Scene &&scene) noexcept;

        Scene(DialogueBox &dialogue_box, std::string &background_file, bool choice_of_action,
              std::vector<Action> &actions);

        ~Scene() override = default;

    private:
        DialogueBox dialogue_box_;
        std::string background_file_;
        bool choice_of_action_;
        std::vector<Action> actions_;

        std::vector<sf::Sprite> getSpriteVector(sf::Vector2i window_size) override;
    };
}
