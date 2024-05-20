#include "save_manager.h"
#include "nlohmann/json.hpp"

#include <fstream>
#include <iostream>

void ge::SaveManager::putSave(const std::string &chapter_name, size_t frame_number, const std::string &saves_dir, size_t save_index) {
    std::string file_name = saves_dir + "/save" + std::to_string(save_index) + ".txt";

    nlohmann::json j;
    j["chapter_name"] = chapter_name;
    j["frame_number"] = frame_number;

    std::ofstream file(file_name, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Unable to save progress: unable to open file: " << file_name << std::endl;
        return;
    }

    file << j.dump(4);

    file.close();
}


std::pair<std::string, size_t> ge::SaveManager::readSave(const std::string &saves_dir, size_t save_index) {
    std::string file_name = saves_dir + "/save" + std::to_string(save_index) + ".txt";

    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Unable to read save: unable to open file: " << file_name << std::endl;
        return {"", 0};
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    file.close();

    nlohmann::json j;
    try {
        j = nlohmann::json::parse(content);
    } catch (const nlohmann::json::parse_error &e) {
        std::cerr << "Unable to read save: JSON parse error in file " << file_name << ": " << e.what() << std::endl;
        return {"", 0}; // Возвращаем пустую строку и 0, если произошла ошибка парсинга
    }

    std::string chapter_name;
    size_t frame_number;
    try {
        chapter_name = j.at("chapter_name").get<std::string>();
        frame_number = j.at("frame_number").get<size_t>();
    } catch (const nlohmann::json::type_error &e) {
        std::cerr << "Unable to read save: JSON type error in file " << file_name << ": " << e.what() << std::endl;
        return {"", 0};
    }

    return {chapter_name, frame_number};
}

void ge::SaveManager::resetSave(const std::string &saves_dir, size_t save_index) {
    std::string file_name = saves_dir + "/save" + std::to_string(save_index) + ".txt";
    std::remove(file_name.c_str());
}