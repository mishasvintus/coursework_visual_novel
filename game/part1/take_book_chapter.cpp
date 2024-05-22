#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeTakeBookChapter() {
    ge::DialogueBox dialogue_box_1(L"Саша", L"Спасибо, с меня булочка в столовой!");
    ge::FrameSlots frame_slots_1({POLINA_BASE_MUTELY});
    ge::Frame frame_1(dialogue_box_1, STREET, frame_slots_1);

    ge::DialogueBox dialogue_box_2(L"", L"За разговорами о домашке мы незаметно дошли до школы. ");
    ge::Frame frame_2(dialogue_box_2, SCHOOL, frame_slots_1);

    ge::DialogueBox dialogue_box_3(L"", L"В раздевалке Полина смешалась с толпой одноклассников и исчезла.");
    ge::FrameSlots frame_slots_3;
    ge::Frame frame_3(dialogue_box_3, HALLWAY, frame_slots_3);

    ge::Action action_1({0.25, 0.55}, L"Оглянуться в поисках Полины", "find_poline");
    ge::Action action_2({0.65, 0.75}, L"Оставить одежду и продолжить путь к кабинету", "dont_find_poline");
    ge::Frame frame_4({action_1, action_2}, HALLWAY, frame_slots_3);
    return ge::Chapter("take_book_chapter", {frame_1, frame_2, frame_3, frame_4});
}