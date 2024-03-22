#include <SFML/Graphics.hpp>

namespace ge {

    const std::string DEFAULT_PROJECT_NAME = "Project";

    class Application {
    public:
        explicit Application();
        explicit Application(const std::string &project_name);
        explicit Application(const Application &other) = delete;
        explicit Application(const Application &&other) = delete;
        ~Application() = default;

        void Finish();

    private:
        static void ApplyRendering(const std::string &project_name);

        sf::Thread rendering_thread_;
    };
}
