#pragma once

#include "scene.h"
#include "script.h"

#include <string>

namespace ge {
    class VisualNovel {
    public:
        VisualNovel() = default;

        VisualNovel(const VisualNovel &visual_novel) = default;

        VisualNovel(VisualNovel &visual_novel) = default;

        VisualNovel(VisualNovel &&visual_novel) noexcept;

        VisualNovel(std::string about_authors, Script script);

        ~VisualNovel() = default;

        bool setAboutAuthors(const std::string &about_authors);

        bool setScript(const Script &script);

        const std::string &getAboutAuthors();

        const Script &getScript();

        bool run(); // TODO: реализовать

    private:
        static constexpr size_t UPPER_BOUND_LENGTH_ABOUT_AUTHORS = 5000;
        std::string about_authors_;
        Script script_;
    };
}
