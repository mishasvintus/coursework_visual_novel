#include <SFML/Graphics.hpp>

#include <string>

class Object {
public:
    virtual ~Object() = default;

    virtual void Draw() {
    }
    //// here will be setters and getters ////
};

class DialogueBox : Object {
public:
    DialogueBox();

    DialogueBox(const std::string_view &replica, const std::string_view &speaker);

    DialogueBox(const DialogueBox &other);
    DialogueBox(const DialogueBox&& other);
    DialogueBox(DialogueBox&& other);

    ~DialogueBox() override = default;

    void Draw() override {
        //// will be realise
    }

    std::string_view GetReplica();

    std::string_view GetSpeaker();

    void SetReplica(const std::string_view& replica);

    void SetSpeaker(const std::string_view& speaker);

private:
    const std::string_view DEFAULT_REPLICA = "Some strange sounds...";
    const std::string_view DEFAULT_SPEAKER = "Some strange creature";

    std::string_view replica_;
    std::string_view speaker_;

    //// will be more params ////
};
