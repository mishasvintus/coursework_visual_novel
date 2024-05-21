#pragma once

#include "visual_novel/visual_novel.h"

struct ChapterFactory {
    ge::Chapter makeFirstChapter();
    ge::Chapter makeCatWatchingChapter();
    ge::Chapter makeGuitarChapter();

    const std::string ABSTRACTION = "game_data/images/locations/abstraction.PNG";
    const std::string ROOM = "game_data/images/locations/room.PNG";

    const std::string NATALYA_NIKOLAEVNA_WEDDING_MUTELY = "game_data/images/character_models/natalya_nikolaevna/wedding_mutely.png";
    const std::string NATALYA_NIKOLAEVNA_WEDDING_TALKING = "game_data/images/character_models/natalya_nikolaevna/wedding_talking.png";
    const std::string OLEG_GOP_MUTELY = "game_data/images/character_models/oleg/gop_mutely.png";
    const std::string OLEG_GOP_TALKING = "game_data/images/character_models/oleg/gop_talking.png";
    const std::string CAT = "game_data/images/mascot/cat.png";
};