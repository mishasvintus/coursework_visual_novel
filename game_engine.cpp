#include "game_engine.h"

#include <utility>
#include <variant>

ge::VarImpl var_impl;

ge::DialogueBox::DialogueBox()
    : replica_(DEFAULT_REPLICA)
    , speaker_(DEFAULT_SPEAKER) {
    var_impl.Push(*this);
}

ge::DialogueBox::DialogueBox(const std::string_view& replica, const std::string_view& speaker)
    : replica_(replica)
    , speaker_(speaker) {
    var_impl.Push(*this);
}

ge::DialogueBox::DialogueBox(const DialogueBox& other)
    : replica_(other.replica_)
    , speaker_(other.speaker_) {
    var_impl.Push(*this);
}

ge::DialogueBox::DialogueBox(const DialogueBox&& other) noexcept
    : replica_(other.replica_)
    , speaker_(other.speaker_) {
    var_impl.Push(*this);
}

ge::DialogueBox::DialogueBox(DialogueBox&& other) noexcept
    : replica_(other.replica_)
    , speaker_(other.speaker_) {
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

ge::Scene::Scene() {
    //// not default, because may be class will have more params
    is_showing_ = false;
}

ge::Scene::Scene(const ge::DialogueBox& dialogue_box) {
    dialogue_box_ = std::make_shared<DialogueBox>(dialogue_box);
}

ge::Scene::Scene(const ge::Scene& scene) {
    is_showing_ = scene.is_showing_;
    dialogue_box_ = scene.dialogue_box_;
    count_slots_ = scene.count_slots_;
}

ge::Scene::Scene(const ge::Scene&& scene) noexcept {
    is_showing_ = scene.is_showing_;
    dialogue_box_ = scene.dialogue_box_;
    count_slots_ = scene.count_slots_;
}

ge::Scene::Scene(ge::Scene&& scene) noexcept {
    is_showing_ = scene.is_showing_;
    dialogue_box_ = scene.dialogue_box_;
    count_slots_ = scene.count_slots_;
}

void ge::Scene::SetDialogueBox(const ge::DialogueBox& dialogue_box) {
    dialogue_box_ = std::make_shared<DialogueBox>(dialogue_box);
}

void ge::Scene::SetDialogueBox(const std::string_view& replica, const std::string_view& speaker) {
    dialogue_box_ = std::make_shared<DialogueBox>(DialogueBox(replica, speaker));
}

std::shared_ptr<ge::DialogueBox> ge::Scene::GetDialogueBox() {
    return dialogue_box_;
}

ge::Application::Application(std::string project_name)
    : project_name_(std::move(project_name)) {
}

ge::Application::Application(std::string project_name, std::string icon_path)
    : project_name_(std::move(project_name))
    , icon_path_(std::move(icon_path)) {
}

void TryParseIconPath(sf::Window& window, sf::Image& icon, const std::string& path) {
    if (path.empty()) {
        return;
    }
    if (!icon.loadFromFile(path)) {
        throw std::invalid_argument(
                "when setting up the application icon, an incorrect path to the image was received\n");
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void ThreadRendering(const std::vector<std::variant<std::string, std::shared_ptr<ge::Scene>>>& arguments) {
    sf::Window window(sf::VideoMode::getDesktopMode(), std::get<std::string>(arguments[ge::Application::INDEX_PROJECT_NAME]));
    sf::Image icon;
    TryParseIconPath(window, icon, std::get<std::string>(arguments[ge::Application::INDEX_ICON_PATH]));
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}

void ge::Application::ApplyRendering() {
    const std::vector<std::variant<std::string, std::shared_ptr<Scene>>> arguments = {scene_, project_name_, icon_path_};
    std::thread thread(&ThreadRendering, arguments);
    thread.join();
}

void ge::Application::SetScene(const ge::Scene& scene) {
    scene_ = std::make_shared<Scene>(scene);
}

std::shared_ptr<ge::Scene> ge::Application::GetScene() {
    return scene_;
}
