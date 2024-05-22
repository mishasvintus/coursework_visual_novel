#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeDontFindPoline() {
    ge::DialogueBox dialogue_box_1(L"", L"В школьных коридорах витал запах мела, карандашей и сосисок\n"
                                        "в тесте из школьной столовой.");
    ge::FrameSlots frame_slots_1;
    ge::Frame frame_1(dialogue_box_1, HALLWAY, frame_slots_1);

    ge::DialogueBox dialogue_box_2(L"",
                                   L"Проходя мимо дверей классов, я становился невольным свидетелей\n жизни других школьников. ");
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

    ge::DialogueBox dialogue_box_8(L"",
                                   L"Невольно я замедлился возле её класса. В какой-то момент наши взгляды встретились.");
    ge::Frame frame_8(dialogue_box_8, HALLWAY, frame_slots_4);

    ge::DialogueBox dialogue_box_9(L"",
                                   L"Я сразу сделал вид, что совершенно не смотрю в её сторону, нелепо потупив взор. ");
    ge::Frame frame_9(dialogue_box_9, HALLWAY, frame_slots_4);

    ge::DialogueBox dialogue_box_10(L"", L"Заметила ли она, что я смотрел на неё? Наверное,\n"
                                         "пялятся на незнакомых девушек только “странные”...");
    ge::Frame frame_10(dialogue_box_10, HALLWAY, frame_slots_4);

    ge::DialogueBox dialogue_box_11(L"", L"Неловкость и смятение начали вгонять меня в краску.");
    ge::Frame frame_11(dialogue_box_11, HALLWAY, frame_slots_4);

    ge::DialogueBox dialogue_box_12(L"", L"Я поспешил в свой класс, где вот-вот должна была начаться математика. ");
    ge::Frame frame_12(dialogue_box_12, CABINET, frame_slots_1);

    ge::DialogueBox dialogue_box_13(L"", L"До начала первого урока оставалась всего пара-тройка минут, поэтому я как никогда\n"
                                         " быстро забежал в кабинет, раскрыл тетрадь по математике и начал переносить в неё\n"
                                         " Полинино решение под непрекращающийся гул голосов одноклассников.");
    ge::Frame frame_13(dialogue_box_13, CABINET, frame_slots_1);

    ge::DialogueBox dialogue_box_14(L"", L"Не понимаю, что она там написала, но выглядит правильно ");
    ge::Frame frame_14(dialogue_box_14, CABINET, frame_slots_1);

    ge::DialogueBox dialogue_box_15(L"", L"Вроде, правильно");
    ge::Frame frame_15(dialogue_box_15, CABINET, frame_slots_1);

    ge::DialogueBox dialogue_box_16(L"", L"В любой другой день я бы с радостью обсудил с одноклассниками прошедшие выходные,\n"
                                      "но сейчас нельзя было медлить - на горизонте маячила двойка за домашнюю работу.\n"
                                      "Этого нельзя было допустить!");
    ge::Frame frame_16(dialogue_box_16, CABINET, frame_slots_1);

    ge::DialogueBox dialogue_box_17(L"", L"Увлекшись заданием, я не заметил, как на плечо легла чья-то рука,\n"
                                         "а шум в кабинете затих. Даже Димас, самый отпетый задира, перестал громко\n"
                                         "выкрикивать шутки. ");
    ge::Frame frame_17(dialogue_box_17, CABINET, frame_slots_1);

    ge::DialogueBox dialogue_box_18(L"", L"Обернувшись, я понял, что Наталья Николаевна, наша учительница по математике\n,"
                                         "смотрит прямо на меня. И смотрит весьма недобро: она заметила,\n"
                                         "как я списываю домашнее задание.");


    return ge::Chapter("dont_find_poline",
                       {frame_1, frame_2, frame_3, frame_4, frame_5, frame_6, frame_7, frame_8, frame_9, frame_10,
                        frame_11, frame_12, frame_13, frame_14, frame_15, frame_16, frame_17});
}