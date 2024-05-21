#include "save_manager.h"
#include "nlohmann/json.hpp"

#include <fstream>
#include <iostream>

void ge::SaveManager::putSave(const std::string &chapter_name, size_t frame_number,
                              std::queue<std::pair<std::wstring, std::wstring>> recent_script,
                              const std::string &saves_dir, size_t save_index) {
    std::string file_name = saves_dir + "/save" + std::to_string(save_index) + ".txt";

    nlohmann::json j;
    j["chapter_name"] = chapter_name;
    j["frame_number"] = frame_number;
    j["script_size"] = recent_script.size();
    for (size_t i = 0; i < 6; ++i) {
        std::string key_first = "recent_script" + std::to_string(i) + "first";
        std::string key_second = "recent_script" + std::to_string(i) + "second";
        if (!recent_script.empty()) {
            j[key_first] = recent_script.front().first;
            j[key_second] = recent_script.front().second;
            recent_script.pop();
            continue;
        }
        break;
    }

    std::ofstream file;
    file.open(file_name, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Unable to save progress: unable to open file: " << file_name << " maybe its save directory doesn't exist" << std::endl;
        return;
    }

    file << j.dump(4);

    file.close();
}


std::vector<std::variant<std::string, size_t, std::queue<std::pair<std::wstring, std::wstring>>>>
ge::SaveManager::readSave(const std::string &saves_dir, size_t save_index) {
    std::string file_name = saves_dir + "/save" + std::to_string(save_index) + ".txt";
    std::vector<std::variant<std::string, size_t, std::queue<std::pair<std::wstring, std::wstring>>>> error = {"",
                                                                                                               static_cast<size_t>(0)};

    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Unable to read save: unable to open file: " << file_name << " maybe its save directory doesn't exist" << std::endl;
        return error;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    file.close();

    nlohmann::json j;
    try {
        j = nlohmann::json::parse(content);
    } catch (const nlohmann::json::parse_error &e) {
        std::cerr << "Unable to read save: JSON parse error in file " << file_name << ": " << e.what() << std::endl;
        return error; // Возвращаем пустую строку и 0, если произошла ошибка парсинга
    }

    std::string chapter_name;
    size_t frame_number;
    std::queue<std::pair<std::wstring, std::wstring>> recent_script;
    try {
        chapter_name = j.at("chapter_name").get<std::string>();
        frame_number = j.at("frame_number").get<size_t>();
        size_t script_size = j.at("script_size");
        for (size_t i = 0; i < script_size; ++i) {
            std::string key_first = "recent_script" + std::to_string(i) + "first";
            std::string key_second = "recent_script" + std::to_string(i) + "second";
            std::wstring value_first = j.at(key_first);
            std::wstring value_second = j.at(key_second);
            recent_script.push(std::make_pair(value_first, value_second));
        }
    } catch (const nlohmann::json::type_error &e) {
        std::cerr << "Unable to read save: JSON type error in file " << file_name << ": " << e.what() << std::endl;
        return error;
    }

    return {chapter_name, frame_number, recent_script};
}

void ge::SaveManager::resetSave(const std::string &saves_dir, size_t save_index) {
    std::string file_name = saves_dir + "/save" + std::to_string(save_index) + ".txt";
    std::remove(file_name.c_str());
}