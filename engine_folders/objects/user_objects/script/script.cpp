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
