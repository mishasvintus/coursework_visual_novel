#include "chapter.h"

#include <utility>

ge::Chapter::Chapter(std::string chapter_name, const std::vector<Frame> &frames)
    : chapter_name_(std::move(chapter_name))
    , frames_(frames) {
}

ge::Chapter::Chapter(Chapter &&chapter) noexcept
    : chapter_name_(std::move(chapter.chapter_name_))
    , frames_(std::move(chapter.frames_)){
}

ge::Chapter &ge::Chapter::operator=(Chapter &&chapter) noexcept {
    chapter_name_= chapter.chapter_name_;
    frames_ = chapter.frames_;
    return *this;
}

