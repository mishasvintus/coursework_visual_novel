#pragma once

#include "frame.h"

namespace ge {
    struct Chapter {
        Chapter() = default;

        Chapter(const Chapter &chapter) = default;

        Chapter(std::string chapter_name, const std::vector<Frame> &frames);

        Chapter(Chapter &&chapter) noexcept;

        ~Chapter() = default;

        Chapter &operator=(const Chapter &chapter) = default;

        Chapter &operator=(Chapter &&chapter) noexcept;

        std::string chapter_name_;
        std::vector<Frame> frames_;
    };
}
