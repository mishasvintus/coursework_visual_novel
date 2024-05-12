**ge::Action**

Класс представляет собой выбор действия в игровом процессе, выбор которого определяет последовательность происходящих 
событий в сюжете визуальной новеллы. Имеет такие характеристики, как месторасположение (координаты в формате sf::Vector2f,
где первым параметром выступает значение по горизонтальной оси координат, вторым - по вертикальной оси координат, важно 
отметить, что координаты {0.; 0.} - это левый верхний угол, а координаты {1.; 1.} - правый нижний), внешний вид (то есть 
надпись в формате std::wstring) и точка перехода (название главы, к которой следует перейти после выбора данного 
действия в формате std::wstring).

Конструкторы:
    
    Action() // конструктор по умолчанию, координаты левого верхнего угла, пустая надпись, нет точки перехода
    
    Action(const sf::Vector2f &coords, std::wstring text, std::wstring chapter_name_to_go) // конструктор с необходимыми
                                                                                                для полноценной работы аргументами.
    
    Action(const Action &action) // конструктор копирования

    Action(Action &&action) noexcept // move-конструктор

При использовании конструктора с необходимыми аргументами проверяется, что координаты имеют правильный вид, то есть 
значение в множестве [0; 1] x [0; 1].

Операторы:

    Action &operator=(const Action &action) // оператор присваивания с помощью копирования 

    Action &operator=(Action &&action) noexcept // оператор присваивания с помощью move-конструкции

    bool operator==(const Action &action) const // оператор сравнения, возвращает true, если объекты совпадают, и false иначе

Методы: 

    [[nodiscard]] const sf::Vector2f &getCoords() const // возвращает относительные координаты

    [[nodiscard]] const std::wstring &getText() const // возвращает внешний вид действия

    [[nodiscard]] const std::wstring &getChapterNameToGo() const // возвращает точку перехода

    void setRelativeCoords(const sf::Vector2f &relative_coords) // устанавливает относительные координаты, проверяя их корректность

    void setText(const std::wstring &text) // устанавливает внешний вид действия

    void setChapterNameToGo(const std::wstring &chapter_name_to_go) // устанавливает точку перехода

---

**ge::DialogueBox**

Класс представляет собой диалоговое окно. Имеет такие характеристики, как speaker (в формате std::wstring длиной не 
болкк 50 символов) и реплика (в формате std::wstring длиной не более 500 символов).

Конструкторы:

    DialogueBox() // конструктор по умолчанию, speaker и реплика инициализируются пустой строкой
 
    DialogueBox(const DialogueBox &other) // конструктор копирования

    DialogueBox(std::wstring speaker, std::wstring replica) // конструктор с необходимыми для полноценной работы 
                                                                                                        аргументами.

    DialogueBox(DialogueBox &&other) noexcept // move-конструктор

Операторы:

    DialogueBox &operator=(const DialogueBox &other) // оператор присваивания при помощи копирования

    DialogueBox &operator=(DialogueBox &&other) noexcept // оператор присваивания при помощи move-конструкции

    bool operator== (const DialogueBox& dialogue_box) const // оператор проверки равенства: возвращает true, если объекты 
                                                                равны, и false иначе.

    bool operator!= (const DialogueBox& dialogue_box) const; // оператор проверки неравенства: возвращает true, если 
                                                                объекты не равны, и false иначе.

Методы:

    void setReplica(const std::wstring &replica) // устанавливает реплику, проверяя, что ее длина не превышает 500 символов

    void setSpeaker(const std::wstring &speaker) // устанавливает speaker'a, проверяя, что его длина не превышает 50 символов

    [[nodiscard]] const std::wstring &getReplica() const // возвращает реплику

    [[nodiscard]] const std::wstring &getSpeaker() const // возвращает speaker'a

---

**ge::FrameSlots**