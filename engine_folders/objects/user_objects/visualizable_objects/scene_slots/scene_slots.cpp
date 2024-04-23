#include "scene_slots.h"

#include "dialogue_box.h"

void checkingCorrectness(const unsigned int count_slots, const unsigned up_limit_slots,
                         const std::vector<std::string> &slots) {
    if (count_slots > up_limit_slots || slots.size() != count_slots) {
        throw std::invalid_argument(
                "the relationship between the vector size and the number of slots is incorrect, or the number of slots is too large\n");
    }
    sf::Image image;
    for (const std::string& path : slots) {
        if (!image.loadFromFile(path)) {
            throw std::runtime_error("file or file's path is incorrect\n");
        }
    }
}

ge::SceneSlots::SceneSlots()
        : quantity_of_slots_(DEFAULT_COUNT_SLOTS), pictures_in_slots_(std::vector<std::string>()) {
    pictures_in_slots_.resize(DEFAULT_COUNT_SLOTS);
    checkingCorrectness(quantity_of_slots_, UPPER_BOUND_COUNT_SLOTS, pictures_in_slots_);
}

ge::SceneSlots::SceneSlots(const SceneSlots &scene_slots)
        : quantity_of_slots_(scene_slots.quantity_of_slots_), pictures_in_slots_(scene_slots.pictures_in_slots_) {
}

ge::SceneSlots::SceneSlots(unsigned int quantity_of_slots, const std::vector<std::string> &pictures_in_slots)
        : quantity_of_slots_(quantity_of_slots), pictures_in_slots_(pictures_in_slots) {
    checkingCorrectness(quantity_of_slots_, UPPER_BOUND_COUNT_SLOTS, pictures_in_slots_);
}

ge::SceneSlots::SceneSlots(SceneSlots &scene_slots)
        : quantity_of_slots_(scene_slots.quantity_of_slots_), pictures_in_slots_(scene_slots.pictures_in_slots_) {
}

ge::SceneSlots::SceneSlots(SceneSlots &&scene_slots) noexcept
        : quantity_of_slots_(scene_slots.quantity_of_slots_),
          pictures_in_slots_(std::move(scene_slots.pictures_in_slots_)) {
}

ge::SceneSlots &ge::SceneSlots::operator=(const SceneSlots &scene_slots) {
    quantity_of_slots_ = scene_slots.quantity_of_slots_;
    pictures_in_slots_ = scene_slots.pictures_in_slots_;
    return *this;
}

ge::SceneSlots &ge::SceneSlots::operator=(SceneSlots &&scene_slots) noexcept {
    quantity_of_slots_ = scene_slots.quantity_of_slots_;
    pictures_in_slots_ = std::move(scene_slots.pictures_in_slots_);
    return *this;
}

bool ge::SceneSlots::setQuantityOfSlots(unsigned int quantity_of_slots) {
    if (quantity_of_slots > UPPER_BOUND_COUNT_SLOTS) {
        return false;
    }
    quantity_of_slots_ = quantity_of_slots;
    pictures_in_slots_.resize(quantity_of_slots_);
    return true;
}

bool ge::SceneSlots::setPicturesInSlots(const std::vector<std::string> &pictures_in_slots) {
    checkingCorrectness(pictures_in_slots.size(), UPPER_BOUND_COUNT_SLOTS, pictures_in_slots);
    if (pictures_in_slots.size() > UPPER_BOUND_COUNT_SLOTS) {
        return false;
    }
    quantity_of_slots_ = pictures_in_slots.size();
    pictures_in_slots_ = pictures_in_slots;
    return true;
}

unsigned int ge::SceneSlots::getQuantityOfSlots() const {
    return quantity_of_slots_;
}

const std::vector<std::string> &ge::SceneSlots::getPicturesInSlots() const {
    return pictures_in_slots_;
}
