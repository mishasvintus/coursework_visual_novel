#pragma once

#include "visual_novel/visual_novel.h"

struct ChapterFactory {
    ge::Chapter makeFirstChapter();
    ge::Chapter makeCatWatchingChapter();
    ge::Chapter makeGuitarChapter();
    ge::Chapter makeSpiderManChapter();
    ge::Chapter makeKitchenChapter();
    ge::Chapter makePart2Chapter1();
    ge::Chapter makeTakeBookChapter();
    ge::Chapter makeFindPoline();
    ge::Chapter makeDontFindPoline();

    const std::string ABSTRACTION = "game/game_data/images/locations/abstraction.PNG";
    const std::string ROOM = "game/game_data/images/locations/room.PNG";
    const std::string KITCHEN = "game/game_data/images/locations/kitchen.PNG";
    const std::string STREET = "game/game_data/images/locations/street.PNG";
    const std::string SCHOOL = "game/game_data/images/locations/yard.PNG";
    const std::string HALLWAY = "game/game_data/images/locations/hallway.PNG";
    const std::string CABINET = "game/game_data/images/locations/cabinet.PNG";

    const std::string NATALYA_NIKOLAEVNA_WEDDING_MUTELY = "game/game_data/images/character_models/natalya_nikolaevna/wedding_mutely.png";
    const std::string NATALYA_NIKOLAEVNA_WEDDING_TALKING = "game/game_data/images/character_models/natalya_nikolaevna/wedding_talking.png";

    const std::string OLEG_GOP_MUTELY = "game/game_data/images/character_models/oleg/gop_mutely.png";
    const std::string OLEG_GOP_TALKING = "game/game_data/images/character_models/oleg/gop_talking.png";

    const std::string MOTHER_BASE_MUTELY = "game/game_data/images/character_models/mother/base_mutely.png";
    const std::string MOTHER_BASE_TALKING = "game/game_data/images/character_models/mother/base_talking.png";
    const std::string MOTHER_HAPPY_MUTELY = "game/game_data/images/character_models/mother/happy_mutely.png";
    const std::string MOTHER_HAPPY_TALKING = "game/game_data/images/character_models/mother/happy_talking.png";

    const std::string FATHER_SURPRISED_MUTELY = "game/game_data/images/character_models/father/surprised_mutely.png";
    const std::string FATHER_SURPRISED_TALKING = "game/game_data/images/character_models/father/surprised_talking.png";

    const std::string POLINA_BASE_MUTELY = "game/game_data/images/character_models/polina/base_mutely.png";
    const std::string POLINA_BASE_TALKING = "game/game_data/images/character_models/polina/base_talking.png";
    const std::string POLINA_SURPRISED_MUTELY = "game/game_data/images/character_models/polina/surprised_mutely.png";
    const std::string POLINA_SURPRISED_TALKING = "game/game_data/images/character_models/polina/surprised_talking.png";

    const std::string SASHA_BASE_MUTELY = "game/game_data/images/character_models/male_character/base_mutely.png";
    const std::string SASHA_BASE_TALKING = "game/game_data/images/character_models/male_character/base_talking.png";

    const std::string KATE_BASE_MUTELY = "game/game_data/images/character_models/katerina/base_mutely.png";

    const std::string CAT = "game/game_data/images/mascot/cat.png";
};