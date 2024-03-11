Было начато составление эскиза движка, в котором будут присутствовать, как глобальные функции, так и вспомогательные классы, оснащенные методами и использующиеся в функциях (методы и особенности реализации будут описаны в отдельных файлах).

-------------------------------------------------------------------------------------------

(TODO: сделать иерархию классов, чтобы использовать наследование методов отрисовки и т.п.)

**Классы:**

  Scene (сцена), 
  
  Slot (слот), 
  
  Buttom (кнопка), 
  
  Dialogue_box (диалоговое окно), 
  
  Scenario (сценарий).

**Функции (псевдокод прототипов, приближенный к C++):**

  `void set_background_picture(const Picture& picture);                                           // Настройка фона`
  `void set_slot_picture(const size_t slot_number, const Picture& picture),                       // Настройка слотов фона`
  `void set_dialogue_box(const string& speaker, const string& replica, ...),                      // Настройка диалогового окна`
  `void set_actions(const pair<double, double> first_coors, const string& first_action_text, const pair<double, double> second_coors, const string& second_action_text),     // Настройка выбора действий`
  `void set_sound(const Sound& sound, const size_t num_sound_road),                               // Настройка звукового сопровождения`
  `void make_transition(const Picture& picture, const string& text, const time_t time).           // Осуществление перехода между сценами`
  

**Прототипы классов:**

class DialogueBox {

public:

    //// КОНСТРУКТОРЫ, ДЕСТРУКТОР ////
    
private:

    //// МЕТОДЫ ////
    
    void SetSpeaker(...);
    
    void SetReplica(...);
    
    //// ПОЛЯ КЛАССА ////
    
    string speaker_;      // возможно, лучше string_view
    
    string replica_;      // возможно, лучше string_view
    
};

class Slot {

public:

    //// КОНСТРУКТОРЫ, ДЕСТРУКТОР ////
    
private:

    //// МЕТОДЫ ////
    
    void SetPicture(const Picture& picture);
    
    //// ПОЛЯ КЛАССА ////
    
    Picture picture_;
    
};

template <typename T = size_t>

class Buttom {

public:

    //// КОНСТРУКТОРЫ, ДЕСТРУКТОР ////
    
private:

    //// МЕТОДЫ ////
    
    TODO
    
    //// ПОЛЯ КЛАССА ////
    
    Picture picture_;
    
    std::function<T> functor_; 
    
};

class Scene {

public:

    //// КОНСТРУКТОРЫ, ДЕСТРУКТОР////
    
private:

    //// МЕТОДЫ ////
    
    void SetBackGround(...);
    
    void SetSlot(..., size_t number);
    
    void SetDialogueBox(...);
    
    void SetButtom(...);
    
    ////ПОЛЯ КЛАССА////
    
    Picture background_;
    
    DialoguBox dialogue_box_;
    
    std::vector<Slot> slots_;
    
    std::vector<Buttom> buttoms_;
    
};

class Scenario {

public:

    //// КОНСТРУКТОРЫ, ДЕСТРУКТОР ////
    
private:

    //// МЕТОДЫ ////
    
    void Update(const std::string& new_text);
    
    (TODO: персистентность)
    
    //// ПОЛЯ КЛАССА ////
    
    std::vector<std::string> scenario;
    
};

-------------------------------------------------------------------------------------------

Для реализации графического интерфейса планируется использовать библиотеку sfml.
