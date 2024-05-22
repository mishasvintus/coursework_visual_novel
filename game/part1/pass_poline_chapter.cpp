#include "chapter_factory.h"

ge::Chapter ChapterFactory::makePassPoline() {
    ge::DialogueBox dialogue_box_1(L"Саша", L"Какая разница, откуда списывать! Половина класса списала с ГДЗ, даже Полина!");
    ge::FrameSlots frame_slots_1({NATALYA_NIKOLAEVNA_ANGRY_MUTELY});
    ge::Frame frame_1(dialogue_box_1, CABINET, frame_slots_1);

    ge::DialogueBox dialogue_box_2(L"Наталья Николаевна", L"Даа? Ну чтож, честность это похвально, но тогда проведем сегодня\n"
                                        "самостоятельную работу, посмотрим, что вы без списывания можете.");
    ge::FrameSlots frame_slots_2({NATALYA_NIKOLAEVNA_ANGRY_TALKING});
    ge::Frame frame_2(dialogue_box_2, CABINET, frame_slots_2);

    ge::DialogueBox dialogue_box_3(L"Виолетта", L"Ну, спасибо, Виноградов, теперь из-за тебя все отдуваться будем.\n"
                                        "Без тебя же контрольных нам не хватало.");
    ge::Frame frame_3(dialogue_box_3, CABINET, frame_slots_1);

    return ge::Chapter("pass_poline", {frame_1, frame_2, frame_3});
}