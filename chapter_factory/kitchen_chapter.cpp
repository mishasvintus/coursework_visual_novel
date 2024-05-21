#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeKitchenChapter() {
    ge::DialogueBox dialogue_box_1(L"", L"Когда я вышел из комнаты, мама с улыбкой встретила меня у стола.");
    ge::FrameSlots frame_slots_1({MOTHER_HAPPY_MUTELY, FATHER_SURPRISED_MUTELY});
    ge::Frame frame_1(dialogue_box_1, KITCHEN, frame_slots_1);

    return ge::Chapter("kitchen_chapter", {frame_1});
}