#include <memory>
#include <vector>

namespace ge {
    class Object {
    public:
        virtual ~Object() = default;

        virtual void Draw();
    };

    class VarImpl {
    public:
        VarImpl() = default;

        VarImpl(const VarImpl& var_impl);

        VarImpl(VarImpl&& var_impl) noexcept;

        VarImpl(const VarImpl&& var_impl) noexcept;

        ~VarImpl() = default;

        void Push(const Object& object);

    private:
        std::vector<std::shared_ptr<Object>> objects_;
    };
}// namespace ge
