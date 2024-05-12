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

Класс представляет собой слоты, в которых размещаются действующие в конкретном кадре персонажи. Имеет характеристики 
количество слотов (в формате unsigned int в диапазоне [0, 10]) и пути к картинкам, которые будут устанавливаться на 
сцене в качестве слотов (в формате std::vector<<std::string>> длина которого не превышает 10).

Конструкторы:

    FrameSlots() // конструктор по умолчанию, инициализирует количество слотов нулем и вектор путей остается пустой

    FrameSlots(const FrameSlots &frame_slots) // конструктор копирования

    FrameSlots(FrameSlots &&frame_slots) noexcept // move-конструктор

    explicit FrameSlots(const std::vector<std::string> &pictures_in_slots) // конструктор принимающий вектор путей и 
                                                                                проверяющий, что размер вектора не 
                                                                                превосходит 10.

Операторы:

    FrameSlots &operator=(const FrameSlots &frame_slots) // оператор присваивания при помощи копирования

    FrameSlots &operator=(FrameSlots &&frame_slots) noexcept // оператор присваивания при помощи move-конструкции

Методы:

    void setQuantityOfSlots(unsigned int quantity_of_slots) // устанавливает количество слотов

    void setPicturesInSlots(const std::vector<std::string> &pictures_in_slots) // устанавливает вектор путей

    [[nodiscard]] unsigned int getQuantityOfSlots() const // возвращает количество слотов

    [[nodiscard]] const std::vector<std::string> &getPicturesInSlots() const // возвращает вектор путей

---

**ge::Frame**

Класс представляет собой сцену/кадр, которая может содержать диалоговое окно, слоты с персонажами и выбор действий. 
Имеет такие харакетристики, как диалоговое окно (в формате ge::DialogueBox).