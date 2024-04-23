#include "dialogue_box.h"

#include <utility>

void checkingCorrectness(const std::string_view &replica, const std::string_view &speaker, const size_t up_replica,
                         const size_t up_speaker) {
    if (replica.length() > up_replica || speaker.length() > up_speaker) {
        throw std::invalid_argument("length of replica or speaker is so long");
    }
}

ge::DialogueBox::DialogueBox(const DialogueBox &other)
        : replica_(other.replica_), speaker_(other.speaker_) {
    checkingCorrectness(replica_, speaker_, UPPER_BOUND_OF_LENGTH_REPLICA, UPPER_BOUND_OF_LENGTH_SPEAKER);
}

ge::DialogueBox::DialogueBox(std::string replica, std::string speaker)
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

bool ge::DialogueBox::setReplica(const std::string &replica) {
    try {
        checkingCorrectness(replica, speaker_, UPPER_BOUND_OF_LENGTH_REPLICA, UPPER_BOUND_OF_LENGTH_SPEAKER);
        replica_ = replica;
    } catch (...) {
        return false;
    }
    return true;
}

bool ge::DialogueBox::setSpeaker(const std::string &speaker) {
    try {
        checkingCorrectness(replica_, speaker, UPPER_BOUND_OF_LENGTH_REPLICA, UPPER_BOUND_OF_LENGTH_SPEAKER);
        speaker_ = speaker;
    } catch (...) {
        return false;
    }
    return true;
}


const std::string &ge::DialogueBox::getReplica() const {
    return replica_;
}

const std::string &ge::DialogueBox::getSpeaker() const {
    return speaker_;
}
