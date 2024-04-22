#include "chapter.h"

#include <utility>

ge::Chapter::Chapter(std::string chapter_name, const std::vector<Scene> &scenes)
    : chapter_name_(std::move(chapter_name))
    , scenes_(scenes) {
}

ge::Chapter::Chapter(Chapter &&chapter) noexcept
    : chapter_name_(std::move(chapter.chapter_name_))
    , scenes_(std::move(chapter.scenes_)){
}

ge::Chapter &ge::Chapter::operator=(Chapter &&chapter) noexcept {
    chapter_name_= chapter.chapter_name_;
    scenes_ = chapter.scenes_;
    return *this;
}

