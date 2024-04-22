#pragma once

#include <string>

class VisualNovel {
public:
    bool setAboutAuthors(std::string info_about_authors);
    bool setScript();
    bool run();
private:
    std::string _about_authors;
};

