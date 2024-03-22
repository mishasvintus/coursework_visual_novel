#include "object.h"

#include <vector>

namespace ge {

    class Application {
    public:
        explicit Application();

        explicit Application(const std::string &project_name);

        explicit Application(const Application &other) = delete;

        explicit Application(const Application &&other) = delete;

        ~Application() = default;

        void Finish();

        void CreateDialogueBox(const std::string_view& replica, const std::string_view& speaker);

    private:
        static void ApplyRendering(const std::string &project_name);

        const std::string DEFAULT_PROJECT_NAME = "Project";

        sf::Thread rendering_thread_;
        std::vector<Object> objects_;
    };
}
