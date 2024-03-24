#include "object.h"

#include <exception>

void Object::Draw() {
    throw std::logic_error("Can't use this method\n");
}

DialogueBox::DialogueBox() : replica_(DEFAULT_REPLICA), speaker_(DEFAULT_SPEAKER) {
}

DialogueBox::DialogueBox(const std::string_view &replica, const std::string_view &speaker) : replica_(replica),
                                                                                             speaker_(speaker) {
}

DialogueBox::DialogueBox(const DialogueBox &other) : replica_(other.replica_), speaker_(other.speaker_) {
}

DialogueBox::DialogueBox(const DialogueBox&& other) noexcept : replica_(other.replica_), speaker_(other.speaker_) {
}

DialogueBox::DialogueBox(DialogueBox&& other) noexcept : replica_(other.replica_), speaker_(other.speaker_) {
}

std::string_view DialogueBox::GetReplica() {
    return replica_;
}

std::string_view DialogueBox::GetSpeaker() {
    return speaker_;
}

void DialogueBox::SetReplica(const std::string_view& replica) {
    replica_ = replica;
}

void DialogueBox::SetSpeaker(const std::string_view& speaker) {
    speaker_ = speaker;
}
