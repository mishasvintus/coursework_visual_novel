#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeDontFindPoline() {
    ge::DialogueBox dialogue_box_1(L"", L"В школьных коридорах витал запах мела, карандашей и сосисок\n"
                                        "в тесте из школьной столовой.");
    ge::FrameSlots frame_slots_1;
    ge::Frame frame_1(dialogue_box_1, HALLWAY, frame_slots_1);

    ge::DialogueBox dialogue_box_2(L"", L"Проходя мимо дверей классов, я становился невольным свидетелей\n жизни других школьников. ");
    ge::Frame frame_2(dialogue_box_2, HALLWAY, frame_slots_1);

    ge::DialogueBox dialogue_box_3(L"", L"Среди малознакомых лиц я заметил её.");
    ge::Frame frame_3(dialogue_box_3, HALLWAY, frame_slots_1);

    ge::DialogueBox dialogue_box_4(L"", L"Катя… Такая загадочная, такая красивая…");
    ge::FrameSlots frame_slots_4({KATE_BASE_MUTELY});
    ge::Frame frame_4(dialogue_box_4, HALLWAY, frame_slots_4);

    ge::DialogueBox dialogue_box_5(L"", L"Она с интересом наблюдала за воробьями, сидящими на карнизе окна.\n"
                                        "Я часто видел, как она делала небольшие зарисовки птиц на последних страницах своих\n"
                                        "тетрадей.");
    ge::Frame frame_5(dialogue_box_5, HALLWAY, frame_slots_4);

    ge::DialogueBox dialogue_box_6(L"", L"Мы не были знакомы, но я пару раз натыкался на её канал в ТГ,\n"
                                        "где она делилась своими рисунками, фотографиями и размышлениями.");
    ge::Frame frame_6(dialogue_box_6, HALLWAY, frame_slots_4);

    ge::DialogueBox dialogue_box_7(L"", L"Страшно признаться, но один из её нарисованных воробьёв поселился\n"
                                        "у меня дома на рабочем столе ноутбука. Рисунки Кати абсолютно точно особенные. ");
    ge::Frame frame_7(dialogue_box_7, HALLWAY, frame_slots_4);

    ge::DialogueBox dialogue_box_8(L"", L"Невольно я замедлился возле её класса. В какой-то момент наши взгляды встретились.");
    ge::Frame frame_8(dialogue_box_8, HALLWAY, frame_slots_4);

    return ge::Chapter("dont_find_poline", {frame_1, frame_2, frame_3, frame_4, frame_5, frame_6, frame_7, frame_8});
}