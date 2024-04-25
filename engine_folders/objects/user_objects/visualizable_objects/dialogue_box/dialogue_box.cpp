#include "dialogue_box.h"

#include <utility>

void checkingCorrectness(const std::wstring &replica, const std::wstring &speaker, const size_t up_replica,
                         const size_t up_speaker) {
    if (replica.length() > up_replica || speaker.length() > up_speaker) {
        throw std::invalid_argument("length of replica or speaker is so long");
    }
}

ge::DialogueBox::DialogueBox(const DialogueBox &other)
    : replica_(other.replica_), speaker_(other.speaker_) {
    checkingCorrectness(replica_, speaker_, UPPER_BOUND_OF_LENGTH_REPLICA, UPPER_BOUND_OF_LENGTH_SPEAKER);
}

ge::DialogueBox::DialogueBox(std::wstring replica, std::wstring speaker)
    : replica_(std::move(replica)), speaker_(std::move(speaker)) {
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

void ge::DialogueBox::setReplica(const std::wstring &replica) {
    checkingCorrectness(replica, speaker_, UPPER_BOUND_OF_LENGTH_REPLICA, UPPER_BOUND_OF_LENGTH_SPEAKER);
    replica_ = replica;
}

void ge::DialogueBox::setSpeaker(const std::wstring &speaker) {
    checkingCorrectness(replica_, speaker, UPPER_BOUND_OF_LENGTH_REPLICA, UPPER_BOUND_OF_LENGTH_SPEAKER);
    speaker_ = speaker;
}


const std::wstring &ge::DialogueBox::getReplica() const {
    return replica_;
}

const std::wstring &ge::DialogueBox::getSpeaker() const {
    return speaker_;
}
