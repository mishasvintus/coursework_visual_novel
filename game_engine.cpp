#include "game_engine.h"

Application::Application() : rendering_thread_(&ApplyRendering, DEFAULT_PROJECT_NAME) {
    rendering_thread_.launch();
}

Application::Application(const std::string &project_name) : rendering_thread_(&ApplyRendering,
                                                                              project_name) {
    rendering_thread_.launch();
}

void Application::ApplyRendering(const std::string &project_name) {
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

void Application::Finish() {
    rendering_thread_.wait();
}
