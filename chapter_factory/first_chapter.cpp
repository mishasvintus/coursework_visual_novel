#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeFirstChapter() {
    ge::DialogueBox dream_dialogue_1(L"Свадебный регистратор",
                                     L"Согласны ли Вы взять этого пацана в мужья? Клянетесь быть с ним в богатстве и бедности,\n"
                                     "на дискотеках и стрелках с другими группировками?");
    ge::FrameSlots dream_slots_1({NATALYA_NIKOLAEVNA_WEDDING_MUTELY, OLEG_GOP_MUTELY});
    ge::Frame dream_frame_1(dream_dialogue_1, ABSTRACTION, dream_slots_1);

    ge::DialogueBox dream_dialogue_2(L"Наталья Николаевна", L"Согласна.");
    ge::FrameSlots dream_slots_2({NATALYA_NIKOLAEVNA_WEDDING_TALKING, OLEG_GOP_MUTELY});
    ge::Frame dream_frame_2(dream_dialogue_2, ABSTRACTION, dream_slots_2);

    ge::DialogueBox dream_dialogue_3(L"Свадебный регистратор", L"А Вы, жених, согласны взять в жены Наталью?\n"
                                                               "Клянетесь быть с ней в богатстве и бедности, защищать её и обеспечивать?");
    ge::FrameSlots dream_slots_3(dream_slots_1);
    ge::Frame dream_frame_3(dream_dialogue_3, ABSTRACTION, dream_slots_3);

    ge::DialogueBox dream_dialogue_4(L"Олег", L"Согласе…");
    ge::FrameSlots dream_slots_4({NATALYA_NIKOLAEVNA_WEDDING_MUTELY, OLEG_GOP_TALKING});
    ge::Frame dream_frame_4(dream_dialogue_4, ABSTRACTION, dream_slots_4);

    ge::DialogueBox wake_dialogue_1(L"", L"*Звон будильника*");
    ge::FrameSlots wake_slots;
    ge::Frame wake_frame_1(wake_dialogue_1, ROOM, wake_slots);

    ge::DialogueBox wake_dialogue_2(L"", L"Приснится же такое!\n"
                                                        "Права была мать, нужно меньше смотреть сериалы перед сном.");
    ge::Frame wake_frame_2(wake_dialogue_2, ROOM, wake_slots);

    ge::DialogueBox wake_dialogue_3(L"",
                                    L"В комнате было тихо, только слабый свет ночной лампы напоминал о ленивом утре.\n"
                                    "Повернув голову, я услышал запах свежесваренного кофе, уже чувствуя, как усталость\n"
                                    "покидает мое тело. ");
    ge::Frame wake_frame_3(wake_dialogue_3, ROOM, wake_slots);

    ge::DialogueBox wake_dialogue_4(L"", L"Вставать определённо не хотелось, но перспектива пропустить очередную\n"
                                         "контрольную не очень радовала. Да и я уже договорился помочь Равшану с выбором новой\n"
                                         "гитары на перемене.");
    ge::Frame wake_frame_4({wake_dialogue_4, ROOM, wake_slots});

    ge::DialogueBox wake_dialogue_5(L"", L"Пора вставать.");
    ge::Frame wake_frame_5({wake_dialogue_5, ROOM, wake_slots});

    ge::Action wake_action_1({0.15, 0.35}, L"Осмотреть кота", "cat_watching");
    ge::Action wake_action_2({0.4, 0.55}, L"Поиграть на гитаре", "guitar_playing");
    ge::Action wake_action_3({0.65, 0.65}, L"Осмотреть плакат с человеком-пауком", "spider_man_watching");
    ge::Action wake_action_4({0.9, 0.85}, L"Выйти на кухню", "kitchen_chapter");
    ge::Frame wake_frame_6({wake_action_1, wake_action_2, wake_action_3, wake_action_4}, ROOM, wake_slots);
    return ge::Chapter("chapter1",
                       {dream_frame_1, dream_frame_2, dream_frame_3, dream_frame_4, wake_frame_1, wake_frame_2,
                        wake_frame_3, wake_frame_4, wake_frame_5, wake_frame_6});
}