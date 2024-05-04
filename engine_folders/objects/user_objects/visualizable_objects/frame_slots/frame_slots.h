#pragma once

#include "visualizable.h"

namespace ge {
    class FrameSlots : Visualizable {
    public:
        FrameSlots();

        FrameSlots(const FrameSlots &frame_slots);

        FrameSlots(FrameSlots &frame_slots);

        FrameSlots(FrameSlots &&frame_slots) noexcept;

        FrameSlots(unsigned int quantity_of_slots, const std::vector<std::string> &pictures_in_slots);

        ~FrameSlots() override = default;

        FrameSlots &operator=(const FrameSlots &frame_slots);

        FrameSlots &operator=(FrameSlots &&frame_slots) noexcept;

        void setQuantityOfSlots(unsigned int quantity_of_slots);

        void setPicturesInSlots(const std::vector<std::string> &pictures_in_slots);

        [[nodiscard]] unsigned int getQuantityOfSlots() const;

        [[nodiscard]] const std::vector<std::string> &getPicturesInSlots() const;

    private:

        bool renderSfmlBasis(const sf::Vector2u &window_size) override {
            return true; /// TODO: реализовать
        }

        void clearSfmlBasis() override {
            /// TODO: реализовать
        }

        std::shared_ptr<SfmlBasis> getSfmlBasis() override {
            return {}; /// TODO: реализовать
        }

        static constexpr unsigned int DEFAULT_COUNT_SLOTS = 5;
        static constexpr unsigned int UPPER_BOUND_COUNT_SLOTS = 10;
        unsigned int quantity_of_slots_ = DEFAULT_COUNT_SLOTS;
        std::vector<std::string> pictures_in_slots_;
    };
}
