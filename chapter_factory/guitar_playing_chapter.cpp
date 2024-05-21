#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeGuitarChapter() {
    ge::DialogueBox dialogue_box_1(L"", L"Трунь-трунь");
    ge::FrameSlots frame_slots;
    ge::Frame frame_1(dialogue_box_1, ROOM, frame_slots);

    ge::Action action({0.5, 0.5}, L"Пойти на кухню", "kitchen_chapter");
    ge::Frame frame_2({action}, ROOM, frame_slots);
    return ge::Chapter("guitar_playing", {frame_1, frame_2});
}