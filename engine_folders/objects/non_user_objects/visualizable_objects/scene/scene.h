#pragma once

#include "frame.h"
#include "non_user_objects/visualizable_objects/visualizable.h"
#include "scene_sfml_basis.h"

namespace ge {
    class Scene : Visualizable {
    public:
        Scene();

        explicit Scene(const std::shared_ptr<Frame> &frame, const std::wstring &current_chapter_name,
                       int current_frame_number);

        Scene(const Scene &scene);

        Scene(Scene &scene);

        Scene(Scene &&scene) noexcept;

        ~Scene() override = default;

        Scene &operator=(const Scene &scene);

        Scene &operator=(Scene &&scene) noexcept;

        void setNewFrame(const std::shared_ptr<Frame> &frame);

        void moveUp();

        void moveDown();

        void moveLeft();

        void moveRight();

        unsigned int getSelectedRow() const;

        unsigned int getSelectedColumn() const;

        bool getChoiceOfActions() const;

        const unsigned int ROW_ACTION_OR_DIALOGUE = 0;
        const unsigned int ROW_BUTTONS = 1;
        const unsigned int COLUMN_MENU = 0;
        const unsigned int COLUMN_SETTINGS = 1;
        const unsigned int COLUMN_INFO = 2;

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override;

        void processNewFrame();

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        bool new_frame_is_processed_ = false;
        bool is_waiting_new_frame_ = true;
        std::shared_ptr<const Frame> current_frame_ = nullptr;
        std::shared_ptr<const Frame> new_frame_ = nullptr;

        std::wstring current_chapter_name_;
        int current_frame_number_ = -1;

        std::shared_ptr<SceneSfmlBasis> sfml_basis_ = nullptr;

        unsigned int selected_row_button_ = 0;
        unsigned int selected_column_button_ = 0;
        const std::vector<std::wstring> BUTTON_SYMBOLS = {L"М", L"Н", L"И"};
        const std::wstring NEXT_BUTTON_TEXT = L"Далее";
        const unsigned int BUTTONS_QUANTITY = 3;
        const sf::Color BACKGROUNDS_FILL_COLOR = sf::Color(sf::Color(71,74,81, 120));
        const sf::Color HIGHLIGHT_COLOR = sf::Color(sf::Color(229,228,226));
    };
}