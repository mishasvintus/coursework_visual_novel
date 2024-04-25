#pragma once

#include "visualizable.h"

namespace ge {
    class DialogueBox : Visualizable {
    public:
        DialogueBox() = default;

        DialogueBox(const DialogueBox &other);

        DialogueBox(std::wstring replica, std::wstring speaker);

        DialogueBox(DialogueBox &&other) noexcept;

        DialogueBox &operator=(const DialogueBox &other);

        DialogueBox &operator=(DialogueBox &&other) noexcept;

        ~DialogueBox() override = default;

        bool operator== (const DialogueBox& dialogue_box) const;

        void setReplica(const std::wstring &replica);

        void setSpeaker(const std::wstring &speaker);

        [[nodiscard]] const std::wstring &getReplica() const;

        [[nodiscard]] const std::wstring &getSpeaker() const;

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
        std::wstring replica_;
        std::wstring speaker_;
    };
}
