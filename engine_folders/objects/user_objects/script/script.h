#pragma once

#include "chapter.h"

#include <unordered_map>

namespace ge {
    struct Script {
        Script() = default;

        Script(const Script &script) = default;

        explicit Script(const std::unordered_map<std::string, Chapter> &chapters);

        Script(Script &&script) noexcept;

        ~Script() = default;

        Script &operator=(const Script &script) = default;

        Script &operator=(Script &&script) noexcept;

        void addChapter(const std::string& name, const Chapter& chapter);

        bool eraseChapter(const std::string& name);

        std::unordered_map<std::string, Chapter> chapters_;
    };
}