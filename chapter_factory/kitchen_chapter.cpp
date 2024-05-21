#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeKitchenChapter() {
    ge::DialogueBox dialogue_box_1(L"", L"Когда я вышел из комнаты, мама с улыбкой встретила меня у стола.");
    ge::FrameSlots frame_slots_1({MOTHER_HAPPY_MUTELY, FATHER_SURPRISED_MUTELY});
    ge::Frame frame_1(dialogue_box_1, KITCHEN, frame_slots_1);

    ge::DialogueBox dialogue_box_2(L"Мама", L"Ну ты и соня, наконец-то проснулся!");
    ge::FrameSlots frame_slots_2({MOTHER_HAPPY_TALKING, FATHER_SURPRISED_MUTELY});
    ge::Frame frame_2(dialogue_box_2, KITCHEN, frame_slots_2);

    ge::DialogueBox dialogue_box_3(L"", L"Папа просматривал ленту новостей,\n"
                                        "периодически комментируя события прошлого дня.");
    ge::Frame frame_3(dialogue_box_3, KITCHEN, frame_slots_1);

    ge::DialogueBox dialogue_box_4(L"Папа", L"Прикинь, опять проиграли, 3:2.\n"
                                            "Угораздило же за этих кривоногих болеть....");
    ge::FrameSlots frame_slots_4({MOTHER_HAPPY_MUTELY, FATHER_SURPRISED_TALKING});
    ge::Frame frame_4(dialogue_box_4, KITCHEN, frame_slots_4);

    ge::DialogueBox dialogue_box_5(L"Мама", L"Не ворчи с утра пораньше.");
    ge::FrameSlots frame_slots_5({MOTHER_HAPPY_TALKING, FATHER_SURPRISED_MUTELY});
    ge::Frame frame_5(dialogue_box_5, KITCHEN, frame_slots_5);

    ge::DialogueBox dialogue_box_6(L"Мама", L"Сашенька, ешь блины скорее, а то в школу опоздаешь!");
    ge::Frame frame_6(dialogue_box_6, KITCHEN, frame_slots_5);

    ge::DialogueBox dialogue_box_7(L"", L"Я приобщился к столу, чувствуя,\n"
                                        "как жизнь начинает пробуждаться вместе со мной.");
    ge::Frame frame_7(dialogue_box_7, KITCHEN, frame_slots_1);

    ge::DialogueBox dialogue_box_8(L"", L"Завтрак, а с ним и с самая приятная часть утра, закончился.");
    ge::Frame frame_8(dialogue_box_8, KITCHEN, frame_slots_1);

    ge::DialogueBox dialogue_box_9(L"", L"Пора собираться в школу.\n"
                                        "Свитер, футболка и брюки лежали на стуле: что же сегодня надеть?..");
    ge::FrameSlots frame_slots_9;
    ge::Frame frame_9(dialogue_box_9, ROOM, frame_slots_9);

    ge::DialogueBox dialogue_box_10(L"", L"Я оделся потеплее, зная, что погода еще не летняя.\n"
                                         " На улице уже не так холодно, но апрельский ветер всё ещё не очень приятно обдувал лицо. ");
    ge::Frame frame_10(dialogue_box_10, STREET, frame_slots_9);

    ge::DialogueBox dialogue_box_11(L"", L"Настроение улучшается, когда в наушниках начинает играть тот самый трек. \n"
                                         "Конечно же, это Анна Асти - Царица!");
    ge::Frame frame_11(dialogue_box_11, STREET, frame_slots_9);

    ge::DialogueBox dialogue_box_12(L"",
                                    L"На деревьях уже появились первые робкие почки, и даже самые утомлённые жители\n"
                                    " города начинали чувствовать власть весны. Даже старушки на лавочках казались\n более приветливыми, чем обычно.");
    ge::Frame frame_12(dialogue_box_12, STREET, frame_slots_9);

    ge::DialogueBox dialogue_box_13(L"", L"Мысли немного опережали течение времён года. Хотелось помечтать о лете,\n"
                                         " каникулах и отдыхе…");
    ge::Frame frame_13(dialogue_box_13, STREET, frame_slots_9);

    ge::DialogueBox dialogue_box_14(L"", L"Кто-то схватил меня за плечо!");
    ge::Frame frame_14(dialogue_box_14, STREET, frame_slots_9);

    ge::DialogueBox dialogue_box_15(L"Кто-то", L"Саша!");
    ge::Frame frame_15(dialogue_box_15, STREET, frame_slots_9);

    ge::DialogueBox dialogue_box_16(L"", L"Резкий вдох застрял где-то в горле.");
    ge::Frame frame_16(dialogue_box_16, STREET, frame_slots_9);

    ge::DialogueBox dialogue_box_17(L"", L"Я обернулся.");
    ge::Frame frame_17(dialogue_box_17, STREET, frame_slots_9);

    ge::DialogueBox dialogue_box_18(L"", L"Рядом стояла моя соседка по парте Полина. Она немного запыхалась,\n"
                                         " видно, заметила меня и пыталась догнать. Как всегда слишком энергичная для начала дня.");
    ge::FrameSlots frame_slots_18({POLINA_BASE_MUTELY});
    ge::Frame frame_18(dialogue_box_18, STREET, frame_slots_18);

    ge::DialogueBox dialogue_box_19(L"", L"Дальше нам по пути, и у нас завязался небольшой разговор.\n"
                                         "Пришлось прервать прослушивание Анны Асти. ");
    ge::Frame frame_19(dialogue_box_19, STREET, frame_slots_18);

    ge::DialogueBox dialogue_box_20(L"Полина", L"Проснись и пой! День обещает быть просто чудесным.");
    ge::FrameSlots frame_slots_20({POLINA_BASE_TALKING});
    ge::Frame frame_20(dialogue_box_20, STREET, frame_slots_20);

    ge::DialogueBox dialogue_box_21(L"Полина", L"Кстати, а ты сделал дз по матеше, задача №487 была сложная такая,\n "
                                               "а в конце учебника ответа на неё нет. Пришлось в ГДЗ лезть! ");
    ge::Frame frame_21(dialogue_box_21, STREET, frame_slots_20);

    ge::DialogueBox dialogue_box_22(L"", L"Точно, матеша… ");
    ge::Frame frame_22(dialogue_box_22, STREET, frame_slots_18);

    ge::DialogueBox dialogue_box_23(L"", L"Все выходные я провела в Sims и мне было совсем не до уроков... ");
    ge::Frame frame_23(dialogue_box_23, STREET, frame_slots_18);

    ge::DialogueBox dialogue_box_24(L"", L"Жаль, Наталья Николаевна не ставит оценки за виртуальную архитектуру");
    ge::Frame frame_24(dialogue_box_24, STREET, frame_slots_18);

    ge::DialogueBox dialogue_box_25(L"Саша", L"Полин, кажется, я опять забыл тетрадь дома. Дашь списать,\n"
                                             " чтобы НН двойку не влепила?");
    ge::Frame frame_25(dialogue_box_25, STREET, frame_slots_18);

    ge::DialogueBox dialogue_box_26(L"Полина", L"Виноградов, вот мы с тобой уже почти год вместе сидим,\n"
                                               "а ты не меняешься. ");
    ge::Frame frame_26(dialogue_box_26, STREET, frame_slots_20);

    return ge::Chapter("kitchen_chapter",
                       {frame_1, frame_2, frame_3, frame_4, frame_5, frame_6, frame_7, frame_8, frame_9, frame_10,
                        frame_11, frame_12, frame_13, frame_14, frame_15, frame_16, frame_17, frame_18, frame_19,
                        frame_20, frame_21, frame_22, frame_23, frame_24, frame_25, frame_26});
}