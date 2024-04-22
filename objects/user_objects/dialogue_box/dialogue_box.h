#pragma once

#include "object.h"

namespace ge {
    class DialogueBox : Object {
    public:
        DialogueBox();

        DialogueBox(const DialogueBox &dialogue_box);

        DialogueBox(DialogueBox &dialogue_box);

        DialogueBox(DialogueBox &&dialogue_box);

        DialogueBox(const std::string &replica, const std::string &speaker);

        ~DialogueBox() = default;

    private:
        std::string replica_;
        std::string speaker_;

        std::vector<sf::Sprite> getSpriteVector(sf::Vector2i window_size) override;
    };
}