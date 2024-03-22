#include "game_engine.h"

ge::Application::Application() : rendering_thread_(&ApplyRendering, DEFAULT_PROJECT_NAME) {
    rendering_thread_.launch();
}

ge::Application::Application(const std::string &project_name) : rendering_thread_(&ApplyRendering,
                                                                              project_name) {
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

void ge::Application::CreateDialogueBox() {
    objects_.emplace_back(std::make_unique<Object>());
}

void ge::Application::CreateDialogueBox(const std::string_view& replica, const std::string_view& speaker) {
    objects_.emplace_back(std::make_unique<DialogueBox>(replica, speaker));
}

void ge::Application::CreateDialogueBox(const DialogueBox &dialogue_box) {
    objects_.emplace_back(std::make_unique<DialogueBox>(dialogue_box));
}

void ge::Application::Finish() {
    rendering_thread_.wait();
}
