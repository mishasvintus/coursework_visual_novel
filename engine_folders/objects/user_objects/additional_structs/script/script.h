#pragma once

#include "chapter.h"

#include <unordered_map>

namespace ge {
    struct Script {
        Script() = default;

        Script(const Script &script) = default;

        explicit Script(const std::unordered_map<std::wstring, Chapter> &chapters);

        Script(Script &&script) noexcept;

        ~Script() = default;

        Script &operator=(const Script &script) = default;

        Script &operator=(Script &&script) noexcept;

        std::unordered_map<std::wstring, Chapter> chapters_;
    };
}
