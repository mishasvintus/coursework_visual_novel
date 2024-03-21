#include <SFML/Graphics.hpp>

void Start(const std::string& project_name) {
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
