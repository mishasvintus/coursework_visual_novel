Курсовой проект.

В настоящий момент основной задачей данного проекта является разработка движка, как вспомогательное средство для создания визуальной новеллы.


Для разработки игрового движка используется библиотеку sfml.

---

Для запуска проекта может потребоваться установка библиотеки sfml, с помощью которой написан движок. В нашем репозитории 
уже прикреплена эта библиотека, но подходящая исключительно для ОС Windows, для Linux или MacOs следует установить ее и 
дать возможность CMakeLists.txt с ней работать. 

CMakeLists.txt в нашем репозитории представлен, как файл формата .md, что 
оправдано разработкой движка с разных ОС.

Для корректного использования движка следует установить директорию сборки в корне проекта.

Для непосредственного использования движка необходимо создать main.cpp, добавить его в CMakeLists.txt и начать работу с 
движком, для его подключения к main.cpp достаточно подключить заголовочный файл "visual_novel/visual_novel.h".

---

Руководство по использованию движка представлено в documentation.md и пополняется.

При неправильном использовании движка программа завершается с сообщением об ошибке.