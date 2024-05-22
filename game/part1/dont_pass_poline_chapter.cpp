#include "chapter_factory.h"

ge::Chapter ChapterFactory::makeDontPassPoline() {
    ge::DialogueBox dialogue_box_1(L"Наталья Николаевна", L"Третьякова, в следующий раз лучше следи за своими вещами.\n"
                                        "Два я тебе ставить не буду. Сегодня разберем новую тему…");
    ge::FrameSlots frame_slots_1({NATALYA_NIKOLAEVNA_ANGRY_TALKING});
    ge::Frame frame_1(dialogue_box_1, CABINET, frame_slots_1);
    return ge::Chapter("dont_pass_poline", {frame_1});
}