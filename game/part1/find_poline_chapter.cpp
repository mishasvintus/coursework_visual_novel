#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeFindPoline() {
    ge::DialogueBox dialogue_box_1(L"", L"Оглянувшись, я не обнаружил в толпе ни Полины,\n"
                                      "ни ее ярко-красной сумки, обычно заметной издалека. ");
    ge::FrameSlots frame_slots_1;
    ge::Frame frame_1(dialogue_box_1, HALLWAY, frame_slots_1);

    ge::DialogueBox dialogue_box_2(L"", L"Сочувственно вздохнув, я направился к кабинету в одиночестве,\n"
                                        " размышляя о том, что же приготовил мне сегодняшний день.");
    ge::Frame frame_2(dialogue_box_2, HALLWAY, frame_slots_1);

    ge::Action action({0.5, 0.7}, L"Пойти к кабинету", "dont_find_poline");
    ge::Frame frame_3({action}, HALLWAY, frame_slots_1);

    return ge::Chapter("find_poline", {frame_1, frame_2, frame_3});
}