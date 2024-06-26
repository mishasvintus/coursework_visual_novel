#include "dialogue_box.h"

#include <utility>
#include <stdexcept>

void checkingCorrectness(const std::wstring &speaker, const std::wstring &replica, const size_t up_speaker,
                         const size_t up_replica) {
    if (speaker.length() > up_speaker || replica.length() > up_replica) {
        throw std::invalid_argument("length of replica or speaker is so long");
    }
}

ge::DialogueBox::DialogueBox(const DialogueBox &other)
        : speaker_(other.speaker_), replica_(other.replica_) {
    checkingCorrectness(speaker_, replica_, UPPER_BOUND_OF_LENGTH_SPEAKER, UPPER_BOUND_OF_LENGTH_REPLICA);
}

ge::DialogueBox::DialogueBox(std::wstring speaker, std::wstring replica)
        : speaker_(std::move(speaker)), replica_(std::move(replica)) {
    checkingCorrectness(speaker_, replica_, UPPER_BOUND_OF_LENGTH_SPEAKER, UPPER_BOUND_OF_LENGTH_REPLICA);
}

ge::DialogueBox::DialogueBox(DialogueBox &&other) noexcept {
    speaker_ = other.speaker_;
    replica_ = other.replica_;
}

bool ge::DialogueBox::operator==(const DialogueBox &dialogue_box) const {
    return speaker_ == dialogue_box.speaker_ && replica_ == dialogue_box.replica_;
}

bool ge::DialogueBox::operator!=(const ge::DialogueBox &dialogue_box) const {
    return speaker_ != dialogue_box.speaker_ || replica_ != dialogue_box.replica_;
}

ge::DialogueBox &ge::DialogueBox::operator=(const DialogueBox &other) {
    speaker_ = other.speaker_;
    replica_ = other.replica_;
    return *this;
}

ge::DialogueBox &ge::DialogueBox::operator=(DialogueBox &&other) noexcept {
    speaker_ = other.speaker_;
    replica_ = other.replica_;
    return *this;
}

void ge::DialogueBox::setReplica(const std::wstring &replica) {
    checkingCorrectness(speaker_, replica, UPPER_BOUND_OF_LENGTH_SPEAKER, UPPER_BOUND_OF_LENGTH_REPLICA);
    replica_ = replica;
}

void ge::DialogueBox::setSpeaker(const std::wstring &speaker) {
    checkingCorrectness(speaker, replica_, UPPER_BOUND_OF_LENGTH_SPEAKER, UPPER_BOUND_OF_LENGTH_REPLICA);
    speaker_ = speaker;
}


const std::wstring &ge::DialogueBox::getReplica() const {
    return replica_;
}

const std::wstring &ge::DialogueBox::getSpeaker() const {
    return speaker_;
}
