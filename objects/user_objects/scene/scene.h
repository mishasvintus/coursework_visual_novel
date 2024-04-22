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

        ~Scene() = default;


    private:
        DialogueBox dialogue_box_;
        std::string background_file_;
        bool choice_of_action_;
        sf::Vector2<Action> actions_;
        std::vector<sf::Sprite> getSpriteVector(sf::Vector2i window_size) override;
    };
}
