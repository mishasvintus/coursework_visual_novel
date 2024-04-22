#pragma once

#include "scene.h"

namespace ge {
    struct Chapter {
        std::string chapter_name;
        std::vector<Scene> scenes;
    };
}