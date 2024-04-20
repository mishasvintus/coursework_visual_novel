#include "object.h"

#include <SFML/Graphics.hpp>

#include <string>
#include <thread>

namespace ge {

    class DialogueBox : public Object {
    public:
        DialogueBox();

        DialogueBox(const std::string_view& replica, const std::string_view& speaker);

        DialogueBox(const DialogueBox& other);

        DialogueBox(const DialogueBox&& other) noexcept;

        DialogueBox(DialogueBox&& other) noexcept;

        ~DialogueBox() override = default;

        std::string_view GetReplica();

        std::string_view GetSpeaker();

        void SetReplica(const std::string_view& replica);

        void SetSpeaker(const std::string_view& speaker);

        void Show();

        void Hide();

    private:
        const std::string_view DEFAULT_REPLICA = "Some strange sounds...";
        const std::string_view DEFAULT_SPEAKER = "Some strange creature";

        bool is_showing_ = false;
        std::string_view replica_;
        std::string_view speaker_;

        //// will be more params ////
    };

    class Scene : public Object {
    public:
        Scene();

        explicit Scene(const DialogueBox& dialogue_box);

        Scene(const Scene& scene);

        Scene(const Scene&& scene) noexcept ;

        Scene(Scene&& scene) noexcept ;

        void SetDialogueBox(const DialogueBox& dialogue_box);

        void SetDialogueBox(const std::string_view& replica, const std::string_view& speaker);

        std::shared_ptr<ge::DialogueBox> GetDialogueBox();

    private:
        static const size_t DEFAULT_SLOTS_COUNT = 5;

        bool is_showing_ = false;
        size_t count_slots_ = DEFAULT_SLOTS_COUNT;
        std::shared_ptr<DialogueBox> dialogue_box_ = nullptr;
    };

    class Application {
    public:
        Application() = default;

        explicit Application(std::string  project_name);

        explicit Application(std::string  project_name, std::string  icon_path);

        explicit Application(const Application& other) = delete;

        explicit Application(const Application&& other) = delete;

        ~Application() = default;

        void SetScene(const Scene& scene);

        std::shared_ptr<ge::Scene> GetScene();

        void ApplyRendering();

        static const size_t INDEX_PROJECT_NAME = 0;
        static const size_t INDEX_ICON_PATH = 1;
        const std::string DEFAULT_PROJECT_NAME = "Project";
        const std::string DEFAULT_IMAGE_ICON_PATH;

    private:
        std::string project_name_ = DEFAULT_PROJECT_NAME;
        std::string icon_path_ = DEFAULT_IMAGE_ICON_PATH;
        std::shared_ptr<Scene> scene_ = nullptr;
    };
}// namespace ge
