#include "script.h"

ge::Script::Script(const std::unordered_map<std::wstring, Chapter> &chapters)
        : chapters_(chapters) {
}

ge::Script::Script(Script &&script) noexcept
        : chapters_(std::move(script.chapters_)) {
}

ge::Script &ge::Script::operator=(Script &&script) noexcept {
    chapters_ = std::move(script.chapters_);
    return *this;
}

void ge::Script::addChapter(const std::wstring &name, const ge::Chapter &chapter) {
    chapters_[name] = chapter;
}

bool ge::Script::eraseChapter(const std::wstring &name) {
    if (chapters_.find(name) == chapters_.end()) {
        return false;
    }
    chapters_.erase(name);
    return true;
}