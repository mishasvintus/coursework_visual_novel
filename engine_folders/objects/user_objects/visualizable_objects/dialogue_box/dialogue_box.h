#pragma once

#include "visualizable.h"

namespace ge {
    class DialogueBox : Visualizable {
    public:
        DialogueBox() = default;

        DialogueBox(const DialogueBox &other);

        DialogueBox(std::string replica, std::string speaker);

        DialogueBox(DialogueBox &&other) noexcept;

        DialogueBox &operator=(const DialogueBox &other);

        DialogueBox &operator=(DialogueBox &&other) noexcept;

        ~DialogueBox() override = default;

        void setReplica(const std::string &replica);

        void setSpeaker(const std::string &speaker);

        [[nodiscard]] const std::string &getReplica() const;

        [[nodiscard]] const std::string &getSpeaker() const;

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

        static constexpr size_t UPPER_BOUND_OF_LENGTH_SPEAKER = 50;
        static constexpr size_t UPPER_BOUND_OF_LENGTH_REPLICA = 500;
        std::string replica_;
        std::string speaker_;
    };
}