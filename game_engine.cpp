#include "game_engine.h"

ge::VarImpl var_impl;

ge::DialogueBox::DialogueBox() : replica_(DEFAULT_REPLICA), speaker_(DEFAULT_SPEAKER) {
    var_impl.Push(*this);
}

ge::DialogueBox::DialogueBox(const std::string_view &replica, const std::string_view &speaker) : replica_(replica),
                                                                                             speaker_(speaker) {
    var_impl.Push(*this);
}

ge::DialogueBox::DialogueBox(const DialogueBox &other) : replica_(other.replica_), speaker_(other.speaker_) {
    var_impl.Push(*this);
}

ge::DialogueBox::DialogueBox(const DialogueBox&& other) noexcept : replica_(other.replica_), speaker_(other.speaker_) {
    var_impl.Push(*this);
}

ge::DialogueBox::DialogueBox(DialogueBox&& other) noexcept : replica_(other.replica_), speaker_(other.speaker_) {
    var_impl.Push(*this);
}

std::string_view ge::DialogueBox::GetReplica() {
    return replica_;
}

std::string_view ge::DialogueBox::GetSpeaker() {
    return speaker_;
}

void ge::DialogueBox::SetReplica(const std::string_view& replica) {
    replica_ = replica;
}

void ge::DialogueBox::SetSpeaker(const std::string_view& speaker) {
    speaker_ = speaker;
}

void ge::DialogueBox::Show() {
    is_showing_ = true;
    //// maybe drawing...
}

void ge::DialogueBox::Hide() {
    is_showing_ = false;
    //// maybe redrawing...
}

ge::Application::Application() : rendering_thread_(&ApplyRendering, DEFAULT_PROJECT_NAME),
                                 slots_count_(DEFAULT_SLOTS_COUNT) {
    rendering_thread_.launch();
}

ge::Application::Application(const std::string &project_name, size_t slots_count) : rendering_thread_(&ApplyRendering,
                                                                                                      project_name),
                                                                                    slots_count_(slots_count) {
    rendering_thread_.launch();
}

void ge::Application::ApplyRendering(const std::string &project_name) {
    sf::Window window(sf::VideoMode::getDesktopMode(), project_name);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}

void ge::Application::SetDialogueBox(const DialogueBox &dialogue_box) {
    dialogue_box_ = std::make_shared<DialogueBox>(dialogue_box);
}

void ge::Application::Finish() {
    rendering_thread_.wait();
}
