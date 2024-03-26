#include "object.h"

#include <stdexcept>

void ge::Object::Draw() {
    throw std::logic_error("Can't use this method\n");
}

ge::VarImpl::VarImpl(const VarImpl& var_impl) {
    objects_ = var_impl.objects_;
}

ge::VarImpl::VarImpl(ge::VarImpl &&var_impl) noexcept {
    objects_ = std::move(var_impl.objects_);
}

ge::VarImpl::VarImpl(const ge::VarImpl &&var_impl) noexcept {
    objects_ = var_impl.objects_;
}

void ge::VarImpl::Push(const Object &object) {
    objects_.emplace_back(std::make_shared<Object>(object));
}
