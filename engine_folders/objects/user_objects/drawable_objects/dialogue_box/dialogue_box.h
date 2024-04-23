#pragma once

#include "drawable.h"

#include <string_view>

namespace ge {
    class DialogueBox : Drawable {
    public:
        DialogueBox() = default;

        DialogueBox(const DialogueBox &other);

        DialogueBox(const std::string &replica, const std::string &speaker);

        DialogueBox(DialogueBox &&other) noexcept;

        DialogueBox &operator=(const DialogueBox &other);

        DialogueBox &operator=(DialogueBox &&other) noexcept;

        ~DialogueBox() override = default;

        bool setReplica(const std::string &replica);

        bool setSpeaker(const std::string &speaker);

        const std::string &getReplica();

        const std::string &getSpeaker();

    private:
        std::vector<sf::Sprite> getSpriteVector(const sf::Vector2u &window_size) override {
            return {}; /// TODO: REALISE
        }

        static constexpr size_t UPPER_BOUND_OF_LENGTH_SPEAKER = 50;
        static constexpr size_t UPPER_BOUND_OF_LENGTH_REPLICA = 500;
        std::string replica_;
        std::string speaker_;
    };
}
