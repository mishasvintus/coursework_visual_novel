#pragma once

#include "non_user_objects/visualizable_objects/visualizable.h"

namespace ge {
    class FrameSlots {
    public:
        FrameSlots();

        FrameSlots(const FrameSlots &frame_slots);

        FrameSlots(FrameSlots &frame_slots);

        FrameSlots(FrameSlots &&frame_slots) noexcept;

        FrameSlots(unsigned int quantity_of_slots, const std::vector<std::string> &pictures_in_slots);

        ~FrameSlots() = default;

        FrameSlots &operator=(const FrameSlots &frame_slots);

        FrameSlots &operator=(FrameSlots &&frame_slots) noexcept;

        void setQuantityOfSlots(unsigned int quantity_of_slots);

        void setPicturesInSlots(const std::vector<std::string> &pictures_in_slots);

        [[nodiscard]] unsigned int getQuantityOfSlots() const;

        [[nodiscard]] const std::vector<std::string> &getPicturesInSlots() const;

    private:
        static constexpr unsigned int DEFAULT_COUNT_SLOTS = 5;
        static constexpr unsigned int UPPER_BOUND_COUNT_SLOTS = 10;
        unsigned int quantity_of_slots_ = DEFAULT_COUNT_SLOTS;
        std::vector<std::string> pictures_in_slots_;
    };
}
