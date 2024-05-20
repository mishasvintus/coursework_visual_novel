#include "cache_manager.h"

#include <iostream>
bool ge::CacheManager::loadImage(const std::string &image, bool is_service) {
    if (!images_buffer.contains(image)) {
        images_buffer[image] = std::make_shared<sf::Texture>();
        if (!images_buffer[image]->loadFromFile(image)) {
            images_buffer.erase(image);
            std::cerr << "Error in CacheManager: couldn't load Image from file" << image << std::endl;
            return false;
        }
    }
    if (is_service) {
        service_image_names_.emplace(image);
    }
    return true;
}

void ge::CacheManager::resetImage(const std::string &image, bool is_service) {
    if (is_service) {
        images_buffer.erase(image);
        service_image_names_.erase(image);
        return;
    }
    if (!service_image_names_.contains(image)) {
        images_buffer.erase(image);
    }
}

void ge::CacheManager::resetBuffer(bool delete_service_images) {
    if (delete_service_images) {
        images_buffer.clear();
        service_image_names_.clear();
        return;
    }
    std::unordered_map<std::string, std::shared_ptr<sf::Texture> > new_images_buffer;
    for (const std::string &service_image:service_image_names_) {
        new_images_buffer[service_image] = images_buffer[service_image];
    }
    images_buffer = new_images_buffer;
}

const sf::Texture &ge::CacheManager::getTextureRef(const std::string &image) {
    return *images_buffer[image];
}