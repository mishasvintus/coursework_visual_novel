#pragma once

#include "scene.h"
#include "visualizable.h"
#include "scene_changes_sfml_basic/scene_changes_sfml_basic.h"

namespace ge {
    class SceneChanges : Visualizable {
    public:
        SceneChanges();

        explicit SceneChanges(const std::shared_ptr<Scene> &scene);

        SceneChanges(const SceneChanges &scene_changes);

        SceneChanges(SceneChanges &scene_changes);

        SceneChanges(SceneChanges &&scene_changes) noexcept;

        ~SceneChanges() override = default;

        SceneChanges &operator=(const SceneChanges &scene_changes);

        SceneChanges &operator=(SceneChanges &&scene_changes) noexcept;

        void Update(const std::shared_ptr<Scene> &scene) const;

    private:
        friend class WindowManager;

        bool renderSfmlBasis(const sf::Vector2u &window_size) override {} /// TODO

        void clearSfmlBasis() override;

        std::shared_ptr<SfmlBasis> getSfmlBasis() override;

        bool is_rendered_ = false;
        std::shared_ptr<const Scene> current_scene_ = nullptr;
        std::shared_ptr<SceneChangesSfmlBasic> sfml_basic_ = nullptr;
    };
}
