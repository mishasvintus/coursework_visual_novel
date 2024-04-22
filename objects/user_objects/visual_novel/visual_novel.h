#pragma once

#include <string>
#include "script.h"

namespace ge {
    class VisualNovel {
    public:
        VisualNovel();

        VisualNovel(const VisualNovel &visual_novel);

        VisualNovel(VisualNovel &visual_novel);

        VisualNovel(VisualNovel &&visual_novel);

        ~VisualNovel() = default;


        bool setAboutAuthors(std::string info_about_authors);

        bool setScript();

        bool run();

    private:
        std::string _about_authors;
        ge::Script _script;
    };
}
