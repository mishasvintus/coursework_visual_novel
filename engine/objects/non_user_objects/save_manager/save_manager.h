#pragma once

#include <cstdint>
#include <queue>
#include <string>
#include <variant>
#include <vector>

namespace ge {
    class SaveManager {
    public:
        static void
        putSave(const std::string &chapter_name, size_t frame_number,
                std::queue<std::pair<std::wstring, std::wstring>> recent_script,
                const std::string &saves_dir, size_t save_index);

        static std::vector<std::variant<std::string, size_t, std::queue<std::pair<std::wstring, std::wstring>>>>
        readSave(const std::string &saves_dir, size_t save_index);

        static void resetSave(const std::string &saves_dir, size_t save_index);
    };
}