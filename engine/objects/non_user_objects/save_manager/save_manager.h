#include <cstdint>
#include <string>
namespace ge {
     class SaveManager {
    public:
        static void putSave(const std::string &chapter_name, size_t frame_number, const std::string &saves_dir,  size_t save_index);
        static std::pair<std::string, size_t> readSave(const std::string &saves_dir, size_t save_index);
        static void resetSave(const std::string &saves_dir, size_t save_index);

        static void putRecentScript(const std::string &recent_script);
        static std::string &readRecentScript(const std::string& recent_script);
        static void resetRecentScript(size_t save_index);
    };
}