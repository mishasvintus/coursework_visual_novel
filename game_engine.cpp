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

ge::DialogueBox::DialogueBox(const DialogueBox &&other) noexcept: replica_(other.replica_), speaker_(other.speaker_) {
    var_impl.Push(*this);
}

ge::DialogueBox::DialogueBox(DialogueBox &&other) noexcept: replica_(other.replica_), speaker_(other.speaker_) {
    var_impl.Push(*this);
}

std::string_view ge::DialogueBox::GetReplica() {
    return replica_;
}

std::string_view ge::DialogueBox::GetSpeaker() {
    return speaker_;
}

void ge::DialogueBox::SetReplica(const std::string_view &replica) {
    replica_ = replica;
}

void ge::DialogueBox::SetSpeaker(const std::string_view &speaker) {
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

ge::Application::Application() : rendering_thread_(&ApplyRendering, std::vector<std::string>{DEFAULT_PROJECT_NAME,
                                                                                             DEFAULT_IMAGE_ICON_PATH}) {
}

ge::Application::Application(const std::string &project_name) : rendering_thread_(&ApplyRendering,
                                                                                  std::vector<std::string>{
                                                                                          project_name,
                                                                                          DEFAULT_IMAGE_ICON_PATH}) {
}

ge::Application::Application(const std::string &project_name, const std::string &icon_path) : rendering_thread_(
        &ApplyRendering, std::vector<std::string>{project_name, icon_path}) {
}

void TryParseIconPath(sf::Window& window, sf::Image &icon, const std::string &path) {
    if (path.empty()) {
        return;
    }
    if (!icon.loadFromFile(path)) {
        throw std::invalid_argument(
                "when setting up the application icon, an incorrect path to the image was received\n");
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void ge::Application::ApplyRendering(const std::vector<std::string> &arguments) {
    sf::Window window(sf::VideoMode::getDesktopMode(), arguments[INDEX_PROJECT_NAME]);
    sf::Image icon;
    TryParseIconPath(window, icon, arguments[INDEX_ICON_PATH]);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}

void ge::Application::Start() {
    rendering_thread_.launch();
}

void ge::Application::SetSlotsCount(size_t count) {
    slots_count_ = count;
}

void ge::Application::SetDialogueBox(const DialogueBox &dialogue_box) {
    dialogue_box_ = std::make_shared<DialogueBox>(dialogue_box);
}

void ge::Application::Finish() {
    rendering_thread_.wait();
}
