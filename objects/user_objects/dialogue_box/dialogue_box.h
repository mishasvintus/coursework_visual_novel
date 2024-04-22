#pragma once
#include "object.h"

#include <string_view>

namespace ge {
    class DialogueBox : Object {
    public:
        DialogueBox() = default;

        DialogueBox(const DialogueBox& other);

        DialogueBox(const std::string_view& replica, const std::string_view& speaker);

        DialogueBox(DialogueBox&& other) noexcept;

        DialogueBox& operator=(const DialogueBox& other);

        ~DialogueBox() override = default;

    private:

        std::vector<sf::Sprite> getSpriteVector(sf::Vector2i window_size) override;

        static constexpr size_t UPPER_BOUND_OF_LENGTH_SPEAKER = 50;
        static constexpr size_t UPPER_BOUND_OF_LENGTH_REPLICA = 500;
        std::string_view replica_;
        std::string_view speaker_;
    };
}
