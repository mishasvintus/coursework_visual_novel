#pragma once

#include "frame.h"
#include "non_user_objects/visualizable_objects/visualizable.h"
#include "scene_sfml_basis.h"

namespace ge {
    class Scene : Visualizable {
    public:
        Scene();

        explicit Scene(const std::shared_ptr<Frame> &frame);

        Scene(const Scene &scene);

        Scene(Scene &scene);

        Scene(Scene &&scene) noexcept;

        ~Scene() override = default;

        Scene &operator=(const Scene &scene);

        Scene &operator=(Scene &&scene) noexcept;

        void setNewFrame(const std::shared_ptr<Frame> &frame);

        void MoveUp();

        void MoveDown();

        void MoveLeft();

        void MoveRight();
    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void processNewFrame();

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        bool new_frame_is_processed = false;
        std::shared_ptr<const Frame> current_frame_ = nullptr;
        std::shared_ptr<const Frame> new_frame_ = nullptr;

        std::wstring current_chapter_name_;
        int current_frame_number_ = -1;

        std::shared_ptr<SceneSfmlBasis> sfml_basis_ = nullptr;

        unsigned int selected_row_button_ = 0;
        unsigned int selected_column_button_ = 0;
        const unsigned int ROW_DIALOGUE_BOX = 0;
        const unsigned int COLUMN_DIALOGUE_BOX = 0;
        const unsigned int ROW_ACTIONS = 1;
        const unsigned int ROW_BUTTONS = 2;
        const std::vector<std::wstring> BUTTON_SYMBOLS = {L"М", L"Н", L"И"};
        const unsigned int BUTTONS_QUANTITY = 3;
    };
}
