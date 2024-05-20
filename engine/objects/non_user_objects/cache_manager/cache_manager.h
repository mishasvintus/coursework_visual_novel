#pragma once

#include "SFML/Graphics.hpp"

#include <unordered_map>
#include <unordered_set>
#include <memory>

namespace ge {
    class CacheManager {
    public:
        bool loadImage(const std::string &image, bool is_service);
        void resetImage(const std::string &image, bool is_service);
        void resetBuffer(bool delete_service_images);
        const sf::Texture &getTextureRef(const std::string &image);
    private:
        std::unordered_map<std::string, std::shared_ptr<sf::Texture>> images_buffer;
        std::unordered_set<std::string> service_image_names_;
    };
}

