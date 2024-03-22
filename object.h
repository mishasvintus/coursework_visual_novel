#include <SFML/Graphics.hpp>

#include <string>

class Object {
public:
    virtual ~Object() = default;

    virtual void Draw();

    virtual std::string_view GetReplica();

    virtual std::string_view GetSpeaker();

    virtual void SetReplica(const std::string_view &replica);

    virtual void SetSpeaker(const std::string_view &replica);
};

class DialogueBox : public Object {
public:
    DialogueBox();

    DialogueBox(const std::string_view &replica, const std::string_view &speaker);

    DialogueBox(const DialogueBox &other);

    DialogueBox(const DialogueBox &&other) noexcept;

    DialogueBox(DialogueBox &&other) noexcept;

    ~DialogueBox() override = default;

    std::string_view GetReplica() override;

    std::string_view GetSpeaker() override;

    void SetReplica(const std::string_view &replica) override;

    void SetSpeaker(const std::string_view &speaker) override;

private:
    const std::string_view DEFAULT_REPLICA = "Some strange sounds...";
    const std::string_view DEFAULT_SPEAKER = "Some strange creature";

    std::string_view replica_;
    std::string_view speaker_;

    //// will be more params ////
};
