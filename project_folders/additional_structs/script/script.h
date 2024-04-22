#pragma once

#include <unordered_map>
#include "chapter.h"

namespace ge {
    struct Script {
        std::unordered_map<std::string, Chapter> chapters;
    };
}