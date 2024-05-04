#pragma once

#include "frame.h"
#include "visualizable.h"
#include "scene_sfml_basis/scene_sfml_basis.h"

namespace ge {
    class Scene : Visualizable {
    public:
        Scene();

        explicit Scene(const std::shared_ptr<Frame> &frame);

        Scene(const Scene &scene);

        Scene(Scene &scene);

        Scene(Scene &&scene) noexcept;

        ~Scene() override = default;

        Scene &operator=(const Scene &scene);

        Scene &operator=(Scene &&scene) noexcept;

        void Update(const std::shared_ptr<Frame> &frame) const;

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override {} /// TODO

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        std::shared_ptr<const Frame> current_frame_ = nullptr;
        std::shared_ptr<SceneSfmlBasis> sfml_basic_ = nullptr;
    };
}
