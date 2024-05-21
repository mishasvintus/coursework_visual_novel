#pragma once

#include "sfml_basis.h"
#include "cache_manager.h"

#include <SFML/Graphics.hpp>
#include <memory>

namespace ge {
    class Visualizable {
    public:
        virtual ~Visualizable() = default;

        void setCacheManager(const std::shared_ptr<ge::CacheManager> &cache_manager) {
            cache_manager_ = cache_manager;
        }

        const ge::CacheManager &getCacheManager() {
            return *cache_manager_;
        }

        const std::string FONT_NAME = "engine/data/comic_sans.ttf";
    protected:
        std::shared_ptr<CacheManager> cache_manager_ = nullptr;

    private:
        virtual bool renderSfmlBasis(const sf::Vector2u &window_size) = 0;

        virtual void clearSfmlBasis() = 0;

        virtual std::shared_ptr<SfmlBasis> getSfmlBasis() = 0;
    };
}
