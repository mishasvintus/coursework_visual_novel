cmake_minimum_required(VERSION 3.24)
project(coursework_visual_novel)

set(CMAKE_CXX_STANDARD 23)

include_directories(engine_folders/objects)
include_directories(engine_folders/objects/non_user_objects/visualizable_objects/about_authors)
include_directories(engine_folders/objects/non_user_objects/visualizable_objects/info)
include_directories(engine_folders/objects/non_user_objects/visualizable_objects/ingame_menu)
include_directories(engine_folders/objects/non_user_objects/visualizable_objects/ingame_settings)
include_directories(engine_folders/objects/non_user_objects/visualizable_objects/main_menu)
include_directories(engine_folders/objects/non_user_objects/visualizable_objects/recent_script)
include_directories(engine_folders/objects/non_user_objects/visualizable_objects/settings)
include_directories(engine_folders/objects/non_user_objects/sfml_basis_objects)
include_directories(engine_folders/objects/user_objects)
include_directories(engine_folders/objects/user_objects/actions)
include_directories(engine_folders/objects/user_objects/dialogue_box)
include_directories(engine_folders/objects/user_objects/frame)
include_directories(engine_folders/objects/user_objects/frame_slots)
include_directories(engine_folders/objects/non_user_objects/window_manager)
include_directories(engine_folders/objects/user_objects/chapter)
include_directories(engine_folders/objects/user_objects/script)
include_directories(engine_folders/objects/non_user_objects/elements_to_draw)
include_directories(engine_folders/objects/non_user_objects/sfml_basis_objects/scene_sfml_basis)
include_directories(engine_folders/objects/non_user_objects/visualizable_objects/scene)

add_executable(coursework_visual_novel
engine_folders/objects/non_user_objects/visualizable_objects/about_authors/about_authors.cpp
engine_folders/objects/non_user_objects/visualizable_objects/about_authors/about_authors.h
engine_folders/objects/non_user_objects/visualizable_objects/about_authors/about_authors_sfml_basis.cpp
engine_folders/objects/non_user_objects/visualizable_objects/about_authors/about_authors_sfml_basis.h
engine_folders/objects/non_user_objects/visualizable_objects/info/info.cpp
engine_folders/objects/non_user_objects/visualizable_objects/info/info.h
engine_folders/objects/non_user_objects/visualizable_objects/ingame_menu/ingame_menu.cpp
engine_folders/objects/non_user_objects/visualizable_objects/ingame_menu/ingame_menu.h
engine_folders/objects/non_user_objects/visualizable_objects/ingame_settings/ingame_settings.cpp
engine_folders/objects/non_user_objects/visualizable_objects/ingame_settings/ingame_settings.h
engine_folders/objects/non_user_objects/visualizable_objects/main_menu/main_menu.cpp
engine_folders/objects/non_user_objects/visualizable_objects/main_menu/main_menu.h
engine_folders/objects/non_user_objects/visualizable_objects/recent_script/recent_script.cpp
engine_folders/objects/non_user_objects/visualizable_objects/recent_script/recent_script.h
engine_folders/objects/non_user_objects/visualizable_objects/settings/settings.cpp
engine_folders/objects/non_user_objects/visualizable_objects/settings/settings.h
engine_folders/objects/user_objects/actions/actions.cpp
engine_folders/objects/user_objects/actions/actions.h
engine_folders/objects/user_objects/dialogue_box/dialogue_box.cpp
engine_folders/objects/user_objects/dialogue_box/dialogue_box.h
engine_folders/objects/user_objects/frame/frame.cpp
engine_folders/objects/user_objects/frame/frame.h
engine_folders/objects/user_objects/frame_slots/frame_slots.cpp
engine_folders/objects/user_objects/frame_slots/frame_slots.h
engine_folders/objects/user_objects/visual_novel/visual_novel.cpp
engine_folders/objects/user_objects/visual_novel/visual_novel.h
engine_folders/objects/non_user_objects/visualizable_objects/visualizable.h
engine_folders/objects/user_objects/chapter/chapter.h

engine_folders/objects/user_objects/chapter/chapter.cpp
        engine_folders/objects/user_objects/script/script.cpp
        engine_folders/objects/user_objects/script/script.h
        main.cpp engine_folders/objects/non_user_objects/window_manager/window_manager.h
        engine_folders/objects/non_user_objects/window_manager/window_manager.cpp
        engine_folders/objects/non_user_objects/elements_to_draw/elements_to_draw.cpp
        engine_folders/objects/non_user_objects/elements_to_draw/elements_to_draw.h
        engine_folders/objects/non_user_objects/visualizable_objects/sfml_basis.h
        engine_folders/objects/non_user_objects/visualizable_objects/main_menu/main_menu_sfml_basis.h
        engine_folders/objects/non_user_objects/visualizable_objects/main_menu/main_menu_sfml_basis.cpp
        engine_folders/objects/non_user_objects/visualizable_objects/scene/scene_sfml_basis.cpp
        engine_folders/objects/non_user_objects/visualizable_objects/scene/scene_sfml_basis.h
        engine_folders/objects/non_user_objects/visualizable_objects/scene/scene.cpp
        engine_folders/objects/non_user_objects/visualizable_objects/scene/scene.h engine_folders/objects/non_user_objects/visualizable_objects/settings/settings_sfml_basis.h engine_folders/objects/non_user_objects/visualizable_objects/settings/settings_sfml_basis.cpp)






set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "engine_folders\\SFML\\lib\\cmake\\SFML")

target_link_libraries(coursework_visual_novel sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.6.1 REQUIRED graphics network audio window system)
