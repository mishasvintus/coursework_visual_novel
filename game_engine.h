#include "object.h"

#include <SFML/Graphics.hpp>

#include <string>

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

    class Application {
    public:
        explicit Application();

        explicit Application(const std::string& project_name);

        explicit Application(const std::string& project_name, const std::string& icon_path);

        explicit Application(const Application& other) = delete;

        explicit Application(const Application&& other) = delete;

        ~Application() = default;

        void Start();

        void Finish();

        void SetSlotsCount(size_t count);

        void SetDialogueBox(const DialogueBox& dialogue_box);

    private:
        static void ApplyRendering(const std::vector<std::string>& arguments);

        static const size_t INDEX_PROJECT_NAME = 0;
        static const size_t INDEX_ICON_PATH = 1;
        static const size_t DEFAULT_SLOTS_COUNT = 5;
        const std::string DEFAULT_PROJECT_NAME = "Project";
        const std::string DEFAULT_IMAGE_ICON_PATH;

        sf::Thread rendering_thread_;
        size_t slots_count_ = DEFAULT_SLOTS_COUNT;
        std::shared_ptr<DialogueBox> dialogue_box_ = nullptr;
    };
}// namespace ge
