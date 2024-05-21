#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeCatWatchingChapter() {
    ge::DialogueBox dialogue_box_1(L"", L"О, Фидес у меня снова у меня в комнате спал. Такой он ласковый, такой мягкий и теплый. Очень его люблю, хоть и кусается иногда.");
    ge::FrameSlots frame_slots_1({CAT});
    ge::Frame frame_1(dialogue_box_1, ROOM, frame_slots_1);

    ge::Action action({0.5, 0.5}, L"Пойти на кухню", "kitchen_chapter");
    ge::Frame frame_2({action}, ROOM, frame_slots_1);
    return ge::Chapter("cat_watching", {frame_1, frame_2});
}