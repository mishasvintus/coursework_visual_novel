#pragma once

#include "visualizable.h"

namespace ge {
    class SceneSlots : Visualizable {
    public:
        SceneSlots();

        SceneSlots(const SceneSlots &scene_slots);

        SceneSlots(SceneSlots &scene_slots);

        SceneSlots(SceneSlots &&scene_slots) noexcept;

        SceneSlots(unsigned int quantity_of_slots, const std::vector<std::string> &pictures_in_slots);

        ~SceneSlots() override = default;

        SceneSlots &operator=(const SceneSlots &scene_slots);

        SceneSlots &operator=(SceneSlots &&scene_slots) noexcept;

        bool setQuantityOfSlots(unsigned int quantity_of_slots);

        bool setPicturesInSlots(const std::vector<std::string> &pictures_in_slots);

        [[nodiscard]] unsigned int getQuantityOfSlots() const;

        [[nodiscard]] const std::vector<std::string> &getPicturesInSlots() const;

    private:
        std::vector<sf::Drawable> getDrawableVector(const sf::Vector2u &window_size) override {
            return {}; ///TODO: реализовать
        }

        static constexpr unsigned int DEFAULT_COUNT_SLOTS = 5;
        static constexpr unsigned int UPPER_BOUND_COUNT_SLOTS = 10;
        unsigned int quantity_of_slots_ = DEFAULT_COUNT_SLOTS;
        std::vector<std::string> pictures_in_slots_;
    };
}
