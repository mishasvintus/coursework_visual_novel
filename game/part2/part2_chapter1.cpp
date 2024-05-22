#include "chapter_factory.h"

ge::Chapter ChapterFactory::makePart2Chapter1() {


    ge::DialogueBox dialogue_box(L"", L"");

    ge::FrameSlots pst_sbm({POLINA_BASE_TALKING, SASHA_BASE_MUTELY});
    ge::FrameSlots psm_sbt({POLINA_SURPRISED_MUTELY, SASHA_BASE_TALKING});
    ge::FrameSlots mbt({MOTHER_BASE_TALKING});
    ge::FrameSlots mbm({MOTHER_BASE_MUTELY});
    ge::FrameSlots shm({SASHA_BASE_MUTELY});
    ge::FrameSlots sbt({SASHA_BASE_TALKING});

    ge::DialogueBox dialogue_box1(L"Полина", L" Саша, что с тобой?");
    ge::DialogueBox dialogue_box2(L"Саша", L"А что со мной?");
    ge::DialogueBox dialogue_box3(L"Полина", L"Посмотри в зеркало!");
    ge::DialogueBox dialogue_box4(L"", L"Передо мной появилось огромное зеркало.");
    ge::DialogueBox dialogue_box5(L"", L"В его отражении на меня смотрел…");
    ge::DialogueBox dialogue_box6(L"", L"Немецкий волк-танцор!!!");
    ge::DialogueBox dialogue_box7(L"", L"Лицо Полины застыло в гримасе ужаса, она не переставала кричать..");
    ge::DialogueBox dialogue_box8(L"Полина", L"Сашенька, что с тобой? Что с тобой? Саша!!!!");
    ge::DialogueBox dialogue_box9(L"Голос", L"Саша..");
    ge::DialogueBox dialogue_box10(L"Голос", L"Сашенька, вставай!");
    ge::DialogueBox dialogue_box11(L"Голос", L"Ты будильник проспал");
    ge::DialogueBox dialogue_box12(L"", L"");


    ge::DialogueBox dialogue_box13(L"", L"Открыв глаза, я увидел маму, склонившуюся над моей кроватью.");
    ge::DialogueBox dialogue_box14(L"Мама", L"Сновидение с одноклассницей и персонажем мема развеялось.");
    ge::DialogueBox dialogue_box15(L"Мама", L"Опять в телефоне до поздней ночи сидел, а сейчас вставать не хочешь.");
    ge::DialogueBox dialogue_box16(L"Мама", L"Собирайся скорее, а то опоздаешь.");

    ge::DialogueBox dialogue_box17(L"",
                                   L"Просыпаться совсем не хотелось. Жаль, что от ненавистного понедельника нельзя спрятаться в тёплой постели.");
    ge::DialogueBox dialogue_box18(L"", L"Интересно, что для меня приготовила новая неделя?");
    ge::DialogueBox dialogue_box19(L"",
                                   L"Быстро перекусив бутербродом, я отправился в школу, размышляя о новых модах для Sims.");
    ge::DialogueBox dialogue_box20(L"", L"Как же мне нравится эта игра!");

    ge::DialogueBox dialogue_box21(L"",
                                   L"Зелёные почки на деревьях уже вот-вот должны были превратиться в молодые листочки. Робкие солнечные лучи отражались в окнах многоэтажек.");
    ge::DialogueBox dialogue_box22(L"",
                                   L"Настроение постепенно становилось лучше, да и Анна Асти в наушниках пела сегодня особенно хорошо.");
    ge::DialogueBox dialogue_box23(L"", L"Из-за поворота показался знакомый силуэт с ярко-красной сумкой.");
    ge::DialogueBox dialogue_box24(L"", L"Да это же Полина, прямиком из моего сна!");
    ge::DialogueBox dialogue_box25(L"", L"Я ускорился, чтобы догнать её и напугать также, как она меня неделю назад.");
}