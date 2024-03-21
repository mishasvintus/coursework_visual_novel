#include <SFML/Graphics.hpp>

const std::string DEFAULT_PROJECT_NAME = "Project";

class Application {
public:
    explicit Application();
    explicit Application(const std::string &project_name);
    explicit Application(const Application& other) = delete;
    explicit Application(const Application&& other) = delete;
    ~Application() = default;

    static void ApplyRendering(const std::string &project_name);

    void Finish();

private:
    sf::Thread rendering_thread_;
};
