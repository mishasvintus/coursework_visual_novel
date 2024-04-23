#pragma once

#include "scene.h"

namespace ge {
    struct Chapter {
        Chapter() = default;

        Chapter(const Chapter &chapter) = default;

        Chapter(std::string chapter_name, const std::vector<Scene> &scenes);

        Chapter(Chapter &&chapter) noexcept;

        ~Chapter() = default;

        Chapter &operator=(const Chapter &chapter) = default;

        Chapter &operator=(Chapter &&chapter) noexcept;

        std::string chapter_name_;
        std::vector<Scene> scenes_;
    };
}
