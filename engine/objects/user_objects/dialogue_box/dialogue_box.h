#pragma once

#include "string"

namespace ge {
    class DialogueBox {
    public:
        DialogueBox() = default;

        DialogueBox(const DialogueBox &other);

        DialogueBox(std::wstring speaker, std::wstring replica);

        DialogueBox(DialogueBox &&other) noexcept;

        DialogueBox &operator=(const DialogueBox &other);

        DialogueBox &operator=(DialogueBox &&other) noexcept;

        ~DialogueBox() = default;

        bool operator== (const DialogueBox& dialogue_box) const;

        bool operator!= (const DialogueBox& dialogue_box) const;

        void setReplica(const std::wstring &replica);

        void setSpeaker(const std::wstring &speaker);

        [[nodiscard]] const std::wstring &getReplica() const;

        [[nodiscard]] const std::wstring &getSpeaker() const;

    private:
        static constexpr size_t UPPER_BOUND_OF_LENGTH_SPEAKER = 50;
        static constexpr size_t UPPER_BOUND_OF_LENGTH_REPLICA = 500;
        std::wstring speaker_;
        std::wstring replica_;
    };
}
