#include "dialogue_box.h"

void checkingCorrectness(const std::string_view &replica, const std::string_view &speaker, const size_t up_replica,
                         const size_t up_speaker) {
    if (replica.length() > up_replica || speaker.length() > up_speaker) {
        throw std::invalid_argument("length of replica or speaker is so long");
    }
}

ge::DialogueBox::DialogueBox(const DialogueBox &other)
    : replica_(other.replica_)
      , speaker_(other.speaker_) {
    checkingCorrectness(replica_, speaker_, UPPER_BOUND_OF_LENGTH_REPLICA, UPPER_BOUND_OF_LENGTH_SPEAKER);
}

ge::DialogueBox::DialogueBox(const std::string_view &replica, const std::string_view &speaker)
    : replica_(replica)
      , speaker_(speaker) {
    checkingCorrectness(replica_, speaker_, UPPER_BOUND_OF_LENGTH_REPLICA, UPPER_BOUND_OF_LENGTH_SPEAKER);
}

ge::DialogueBox::DialogueBox(DialogueBox &&other) noexcept {
    replica_ = other.replica_;
    speaker_ = other.speaker_;
}

ge::DialogueBox &ge::DialogueBox::operator=(const DialogueBox &other) {
    replica_ = other.replica_;
    speaker_ = other.speaker_;
    return *this;
}

ge::DialogueBox &ge::DialogueBox::operator=(DialogueBox &&other) noexcept {
    replica_ = other.replica_;
    speaker_ = other.speaker_;
    return *this;
}
