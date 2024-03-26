#include "object.h"

#include <SFML/Graphics.hpp>

#include <string>

namespace ge {

    class DialogueBox : public Object {
    public:
        DialogueBox();

        DialogueBox(const std::string_view &replica, const std::string_view &speaker);

        DialogueBox(const DialogueBox &other);

        DialogueBox(const DialogueBox &&other) noexcept;

        DialogueBox(DialogueBox &&other) noexcept;

        ~DialogueBox() override = default;

        std::string_view GetReplica();

        std::string_view GetSpeaker();

        void SetReplica(const std::string_view &replica);

        void SetSpeaker(const std::string_view &speaker);

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

        explicit Application(const std::string &project_name, size_t slots_count = DEFAULT_SLOTS_COUNT);

        explicit Application(const Application &other) = delete;

        explicit Application(const Application &&other) = delete;

        ~Application() = default;

        void SetDialogueBox(const DialogueBox &dialogue_box);

        void Finish();

    private:
        static void ApplyRendering(const std::string &project_name);

        static const size_t DEFAULT_SLOTS_COUNT = 5;
        const std::string DEFAULT_PROJECT_NAME = "Project";

        sf::Thread rendering_thread_;
        size_t slots_count_;
        std::shared_ptr<DialogueBox> dialogue_box_ = nullptr;
    };
}
