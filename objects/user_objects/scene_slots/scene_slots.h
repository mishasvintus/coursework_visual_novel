#pragma once

#include "object.h"

namespace ge {
    class SceneSlots : Object {
    public:
        SceneSlots();

        SceneSlots(const SceneSlots &scene_slots);

        SceneSlots(SceneSlots &scene_slots);

        SceneSlots(SceneSlots &&sceneSlots);

        SceneSlots(unsigned int quantity_of_slots, const std::vector<std::string> &pictures_in_slots);

        ~SceneSlots() = default;

        bool setQuantityOfSlots(unsigned int quantity_of_slots);

        bool setPicturesInSlots(const std::vector<std::string> &pictures_in_slots);

        unsigned int getQuantityOfSlots();

        std::vector<std::string> getPicturesInSlots();

    private:
        unsigned int quantity_of_slots_;
        std::vector<std::string> pictures_in_slots_;

        std::vector<sf::Sprite> getSpriteVector(const sf::Vector2i &window_size) override;
    };
}