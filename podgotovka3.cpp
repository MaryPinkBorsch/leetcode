#include <iostream>

// ТЕМА номер 4: . Понятие класса и его реализация в языке С++. Объекты.
// Данные и функции класса. Разграничение доступа. Конструкторы и деструкторы. /////////////////////////////////////////////////////////////////////

class A // класс А
{
    // public определяет видимость членов класса (переменных,
    // статических перменных, методов и т.п. "снаружи" класса)

    // кроме public (дефолтный доступ для структур) бывают private (дефолтный для классов),
    // protected (используется при наследовании)
public:
    // ОБЪЯВЛЕНИЕ конструктора и деструктора:
    A();               // конструктор специальный метод, выполняется когда объект создается, используется для получения ресурсов
    A(int array_size); // конструктор с параметром
    ~A();              // деструктор специальный метод, выполняется когда объект уничтожается, используется для освобождения ресурсов

    // переменная класса A имеющая тип int и название a.
    // Это инстанс-переменная(самая обычная переменная класса) - каждый объект класса A имеет свою отдельную a
    int a;
    // ее и объявили и определили ОДНОВРЕМЕННО (так как она инстанс переменная)

    static int stat_a; // это объявление(!) статической переменной stat_a класса А. Статическая переменная - одна на весь класс
    //(если доступавться к статич. переменной с разных объектов типа А а1 и а2,
    // то это обращение к одной и той же переменной стат_а)

    // ОБЪЯВЛЕНИЕ стат. переменных ВСЕГДА внутри класса, как и у обычных переменных-членов класса
    //  при объявлении НЕЛЬЗЯ инициализ-ть СТАТИЧ. переменную
    // ОПРЕДЕЛЕНИЕ всегда ТОЛЬКО в .срр файле ПРИ МНОГОФАЙЛОВОСТИ

    // объявить и определить и инициализировать одновременно ВНУТРИ класса можно только КОНСТАНТНУЮ СТАТИЧЕСКУЮ переменную
    //  например:
    static const int lol = 55; // <--- оно объявлено, иниц-но и определено внутри клсса
    // константу (статич. и обычную) можно инициализировать ТОЛЬКО 1 РАЗ

    // ОПРЕДЕЛЕНИЕ стат. переменной должно быть ВНЕ КЛАССА в глобальной памяти
    //(память под стат. перем-ю создается при начале обработки программы (ее запуске)
    // и уничтожается при завершении работы программы)

    // ИНИЦИАЛИЗИРОВАТЬ стат. переменную = присвоить ей значение (инициализировать можно где угодно)
    // инициализировать статич. перем-ю можно и при ОПРЕДЕЛЕНИИ

    // ОБЪЯВЛЕНИЕ МЕТОДА (внутри класса)
    void print_a(); // объявление метода (функция, принадлежащая этому классу) print_a
    // этот метод работает с инстанс-переменнными и с статическими тоже (просто работает со всеми переменными класса)

    static void plus_stat_a(); // ОБЪЯВЛЕНИЕ статической функции (метода)

    static const int MAX_LEN = 1000;
    int dynamic_int_array_len = 0;
    int *dynamic_int_array = nullptr;

private: // прячет то что дальше от любых функций кроме функций члена класса
    //(статич. функции видят ТОЛЬКО статич. переменные из private,
    // а обычные функции видят ВСЕ переменные из private)

    int aa;

    static int stat_aa; // ее надо определить СНАРУЖИ
};

A::A() // КОНСТРУКТОР - определение
{
    // в конструкторе мы получим память под динамический массив и инциализируем счетчик элементов в нем
    dynamic_int_array = new int[MAX_LEN];
}

A::A(int array_size) // КОНСТРУКТОР с параметром - определение
{
    // в конструкторе мы получим память под динамический массив и инциализируем счетчик элементов в нем
    dynamic_int_array = new int[array_size];
}

A::~A() // ДЕСТРУКТОР - определение
{
    delete[] dynamic_int_array;
    dynamic_int_array = nullptr;
    // деструктор только ОДИН и НЕ ПРИНИМАЕТ параметры ваще
    // конструкторы могут быть несколько но все с разными параметрами
}

// ОПРЕДЕЛЕНИЕ ранее объявленного метода print_a
void A::print_a()
{
    std::cout << " a = " << a << std::endl; // метода класса имеют доступ к ВСЕМ переменным внутри класса,

    std::cout << " stat_a = " << stat_a << std::endl; //  к статич. переменным тоже есть доступ
    // theA.a писать не надо

    ++stat_a;
}

// ОПРЕДЕЛЕНИЕ статичексого метода (static писать только при объявлении!)
void A::plus_stat_a()
{
    // статические методы имеют доступ ТОЛЬКО к статическим членам класса
    ++stat_a;

    // a++; <--- выдаст ОШИБКУ т.к. а - не статич. переменная
}

// это определение(!) статической переменной stat_a класса А. (у нас 1 файл)
// Она определеная в глобальном пространстве имен, и память под нее будет выделена в текущем модуле
int A::stat_a = 33; //(static писать только при объявлении!)

int main(int argc, char *argv[])
{
    // при создании двух объектов (theA и anotherA) для каждого из них автоматичекси вызовется КОНСТРУКТОР (написанный в классе)
    A theA;
    A anotherA;
    A *pA = nullptr; // pA указатель на А

    theA.dynamic_int_array[1] = 10;

    theA.a = 1;
    anotherA.a = 2;
    if (theA.a != anotherA.a)
        std::cout << "разные!!" << std::endl;

    if (theA.stat_a == 0)
        std::cout << "stat_a == 0" << std::endl;

    std::cout << "Адрес theA.stat_a " << &(theA.stat_a) << std::endl;
    std::cout << "Адрес anotherA.stat_a " << &(anotherA.stat_a) << std::endl;
    std::cout << "Адрес A::stat_a " << &(A::stat_a) << std::endl; // такое обращение только для СТАТИЧЕСКИХ переменных

    if (theA.stat_a == anotherA.stat_a && anotherA.stat_a == A::stat_a && theA.stat_a == A::stat_a)
        std::cout << "внезапно это все одно и то же" << std::endl;

    pA = new A(); // это одновременно (!) сначала получит память под А, а потом вызовет для нового объекта констркуктор
    // при получении памяти под объект класса А АВТОМАТИЧЕСКИ вызывается конструктор
    // НО В ЭТОМ СЛУЧАЕ ДЕСТРУКТОР вызовется при удалении объекта,
    //  на который указывает pA с помощью "delete pA"

    theA.print_a();
    A::plus_stat_a(); // статические методы можно вызвать через имя класса "A::"  (стат. переменные ТОЖЕ)
    anotherA.print_a();

    // theA.aa =2222; <--- выдаст ОШИБКУ т.к.  в мейне НЕ ВИДНО  private часть класса

    delete pA; // сначала вызовется деструктор, потом освободится память рА

    pA = new A(1050); // это вызов варианта коснтруктора с параметром
    delete pA;        // и сразу удаление

    return 0;
    // ТУТ вызовутся автоматически деструкторы для двух объектов (theA и anotherA)
    // деструктор вызывается при окончании блока, где были созданы объекты, для их уничтожения
}

// ОТЛИЧИЕ класса от структуры: по умолчанию весь класс - private, а вся структура по умолчанию - public
// видимость можно изменить и в структуре и в классе (нгаписать private: \ public:)
// статические переменнеы и методы работают ОДИНАКОВО в структуре и классе

// НА ПАМЯТЬ: передача параметров в функцию по значению, по указателю и по ссылке

void test(int value, int *p_value, int &ref_value)
{
    value = 1;     // это копия того что передали (уничтожится и в глобальном уровне изменения не сохранятся)
    *p_value = 2;  // разыменуем указатель и изменения с тем, на что он указывает, сохранятся вне функции
    ref_value = 3; // передача по ссылке = работа с той переменной, которая снаружи функции, т.е.
    // все изменения сохранятся на глобальном уровне
}

// ОПРЕДЕЛЕНИЕ СПИСКА (пример для чисел, int) //////////////////////////////////////////////////////

struct IntListNode // ноде - это элемент списка, список это куча объектов структуры,
// каждый из которых содержит указатель на следующий элемент
{
    int value = 0;               // значение этого элемента списка
    IntListNode *next = nullptr; // указатель на следующий элемент списка
};
struct IntList
{
    IntListNode *head = nullptr; // указатель на начало списка
};

// добавление new_val в список после заданного элемента where
void InsertToList(IntListNode *where, int new_val)
{
    IntListNode *tmp = where->next; // сохранили старый "следующий" за where эелмент
    where->next = new IntListNode;  // на его место поставили новый
    where->next->value = new_val;   // присвоили новомоу элементу указанное значение
    where->next->next = tmp;
}

// удаление из списка заданного элемента
void delete_element(IntListNode *to_delete, IntListNode *head)
{
    IntListNode *cur = head;

    if (head == 0 || to_delete == 0)
        return;

    while (cur != nullptr || cur->next != to_delete)
    {
        if (cur->next == 0)
            break;
        cur = cur->next;
    }
    if (cur->next != to_delete)
        std::cout << "oshibka, net elementa for delete";

    else
    {
        IntListNode *tmp = to_delete->next;
        cur->next = tmp;
        delete to_delete;
    }
}

// удалить n-йэлемент из списка
void delete_nomer_el(int n, IntListNode *&head)
{
    int counter = 0;
    IntListNode *cur = head;
    if (head == 0 || n < 0)
        return;

    if (n == 0)
    {
        head = head->next;
        delete cur;
        return;
    }
    else
    {
        while (counter != n - 1)
        {
            if (cur == 0 || cur->next == 0)
            {
                std::cout << "oshibka, net elementa for delete";
                return;
            }
            counter++;
            cur = cur->next;
        }
        if (cur->next == 0)
        {
            std::cout << "oshibka, net elementa for delete";
            return;
        }

        IntListNode *tmp = cur->next->next;
        delete cur->next;
        cur->next = tmp;
    }
}

void print_IntList(IntList &to_print)
{
    IntListNode *cur = to_print.head;
    while (cur != nullptr)
    {
        std::cout << cur->value << ", ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

///////////////////////////////////// решение прикладных задач со списками с файла Exam.2
// struct IntListNode // ноде - это элемент списка, список это куча объектов структуры,
// // каждый из которых содержит указатель на следующий элемент
// {
//     int value = 0;               // значение этого элемента списка
//     IntListNode *next = nullptr; // указатель на следующий элемент списка
// };

// вставить элемент перед последним элементом списка:
void vstavka_pered_poslednim(IntListNode *to_vstavit, IntListNode *&head) // т.к. мы хотим работать и менять голову передаем голову по ссылке
{
    IntListNode *cur = head;
    if (cur == 0)
    {
        std::cout << "oshibka, net elementa for vstavka";
        return;
    }

    if (cur->next == 0)
    {
        IntListNode *tmp = head;
        head = to_vstavit;
        head->next = tmp;
        return;
    }
    while (cur->next->next != 0)
    {
        cur = cur->next;
    }
    if (cur->next->next == 0 && cur->next != 0) // if не обязателен но я так хочу
    {
        IntListNode *tmp = cur->next;
        cur->next = to_vstavit;
        cur->next->next = tmp;
    }
}

// 2)вставить элемент перед первым элементом, имеющим заданное значение;

void vstavka2(IntListNode *to_vstavit, IntListNode *&head, int val)
{
    IntListNode *cur = head;
    if (cur == 0)
    {
        std::cout << "oshibka, net elementa for vstavka";
        return;
    }
    if (cur->value == val)
    {
        IntListNode *tmp = head;
        head = to_vstavit;
        head->next = tmp;
        return;
    }
    while (cur != 0 && cur->next != 0 && cur->next->value != val)
    {
        cur = cur->next;
    }
    if (cur->next == 0)
    {
        std::cout << "oshibka, net elementa for vstavka";
        return;
    }
    else
    {
        IntListNode *tmp = cur->next;
        cur->next = to_vstavit;
        cur->next->next = tmp;
    }
}

void vstavka2_2(IntListNode *to_vstavit, IntListNode **head, int val) // ТУТ 2й УКАЗАТЕЛЬ = указатель по ссылке
{
    IntListNode *cur = *head;
    if (cur == 0)
    {
        std::cout << "oshibka, net elementa for vstavka";
        return;
    }
    if (cur->value == val)
    {
        IntListNode *tmp = *head;
        *head = to_vstavit;
        (*head)->next = tmp; // при разыменовании ДВОЙНОГО указателя получается ОДИНАРНЫЙ (обычный) указатель
        return;
    }
    while (cur != 0 && cur->next != 0 && cur->next->value != val)
    {
        cur = cur->next;
    }
    if (cur->next == 0)
    {
        std::cout << "oshibka, net elementa for vstavka";
        return;
    }
    else
    {
        IntListNode *tmp = cur->next;
        cur->next = to_vstavit;
        cur->next->next = tmp;
    }
}

// 3) элемент перед каждым элементом, имеющим заданное значение;
void vstavka3(IntListNode *to_vstavit, IntListNode **head, int val) // ТУТ 2й УКАЗАТЕЛЬ = указатель по ссылке
{
    IntListNode *cur = *head;
    if (cur == 0)
    {
        std::cout << "oshibka, net elementa for vstavka";
        return;
    }
    if (cur->value == val)
    {
        IntListNode *tmp = *head;
        *head = to_vstavit;
        (*head)->next = tmp; // при разыменовании ДВОЙНОГО указателя получается ОДИНАРНЫЙ (обычный) указатель
    }

    while (cur->next != 0)
    {
        if (cur != 0 && cur->next != 0 && cur->next->value == val)
        {
            IntListNode *tmp = cur->next;
            cur->next = to_vstavit;
            cur->next->next = tmp;
            cur = cur->next;
        }
        cur = cur->next;
    }
}

// 4) элемент после первого элемента, имеющего заданное значение;

void vstavka4(IntListNode **head, int val, int new_val)
{
    if (*head == 0)
        return;

    IntListNode *cur = *head;

    while (cur->next != 0 && cur->value != val)
        cur = cur->next;

    if (cur->value == val)
    {
        IntListNode *to_vstavit = new IntListNode;
        if (to_vstavit != 0) // проверка на выделение памяти
        {
            to_vstavit->value = new_val;

            to_vstavit->next = cur->next;
            cur->next = to_vstavit;
        }
    }
}

// 5) элемент после каждого элемента, имеющего заданное значение;

void vstavka5(IntListNode **head, int val, int new_val)
{
    if (*head == 0)
        return;
    IntListNode *cur = *head;

    while (cur != 0)
    {
        if (cur && cur->value == val)
        {
            IntListNode *to_vstavit = new IntListNode;
            if (to_vstavit != 0) // проверка на выделение памяти
            {
                to_vstavit->value = new_val;
                to_vstavit->next = cur->next;
                cur->next = to_vstavit;
                cur = cur->next; // переходим вперед чтоб не зависнуть в бесконечном цикле
            }
        }
        cur = cur->next;
    }
}

// 12) заданное число элементов после всех элементов, имеющих заданное значение

void vstavka12(int kolvo, int val, int new_val, IntListNode **head)
{
    if (*head == 0)
        return;
    IntListNode *cur = *head;

    while (cur != 0)
    {
        if (cur && cur->value == val)
        {
            for (int i = 0; i < kolvo; i++)
            {
                IntListNode *to_vstavit = new IntListNode;
                if (to_vstavit != 0) // проверка на выделение памяти
                {
                    to_vstavit->value = new_val;
                    to_vstavit->next = cur->next;
                    cur->next = to_vstavit;
                    cur = cur->next; // переходим вперед чтоб не зависнуть в бесконечном цикле
                }
            }
        }
        cur = cur->next; // переходим с последнего вставленного элемента на следующий (to_vstavit->next)
    }
}

// 2. Заменить:  значения n элементов, начиная с элемента с номером k (пусть с 1), заданными значениями соответственно
void zamena(int n, int k, int new_val, IntListNode **head)
{
    if (*head == 0)
        return;
    IntListNode *cur = *head;
    int cur_num = 1;
    while (cur != 0)
    {
        if (cur_num >= k && cur_num < k + n)
            cur->value = new_val;
        cur = cur->next;
        cur_num++;
    }
}

// 4. Найти:  номера всех элементов с заданным значением

void poisk(int find_val, IntListNode **head)
{
    if (*head == 0)
        return;
    IntListNode *cur = *head;
    int cur_num = 1;
    while (cur != 0)
    {
        if (cur->value == find_val)
            std::cout << cur_num << " ";
        cur = cur->next;
        cur_num++;
    }
}

// УДАЛИТЬ
// 1) элемент с заданным номером;              // номер пусть с 0 начинается
void delete1(int nomer, IntListNode **head)
{
    if (*head == 0)
        return;
    IntListNode *cur = *head;
    IntListNode *prev = nullptr;
    int counter = 0;
    while (cur != 0)
    {
        if (counter == nomer)
        {
            if (prev)
            {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
                return;
            }
            else
            {
                *head = cur->next;
                delete cur;
                cur = *head;
                return;
            }
        }
        if (cur)
        {
            prev = cur;
            cur = cur->next;
            counter++;
        }
    }
    std::cout << " Элемент для удаления не найден";
}

// 3) последний по порядку элемент с заданным значением;
void delete3(int del_val, IntListNode **head)
{
    if (*head == 0)
        return;
    IntListNode *cur = *head;
    bool found = false;
    IntListNode *prev = nullptr;
    IntListNode *prev_2 = nullptr; // прев для поиска последнего элемента, после которого идет элемент с заданным значением

    while (cur != 0)
    {
        if (cur->value == del_val)
        {
            prev_2 = prev;
            found = true;
        }
        if (cur)
        {
            prev = cur;
            cur = cur->next;
        }
    }
    if (found)
    {
        if (prev_2)
        {
            IntListNode *tmp = prev_2->next;
            prev_2->next = tmp->next;
            delete tmp;
        }
        else
        {
            IntListNode *tmp = (*head)->next;
            delete *head;
            *head = tmp;
        }
    }
}

// 4) все элементы с заданным значением;
void delete4(int del_val, IntListNode **head)
{
    if (*head == 0)
        return;
    IntListNode *cur = *head;
    bool found = false;
    IntListNode *prev = nullptr;

    while (cur != 0)
    {
        if (cur->value == del_val)
        {
            if (prev)
            {
                prev->next = prev->next->next;
                delete cur;
                cur = prev->next;
            }
            else
            {
                *head = (*head)->next;
                delete cur;
                cur = *head;
            }
        }

        if (cur)
        {
            prev = cur;
            cur = cur->next;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////

// КОНЕЦ штук для списка

//  8. Варианты памяти (static, extern) //////////////////////////////////////////(статик см. в классах)

// если в двух .h файлах объявить extern int g_i, и определить в ОДНОМ .срр файле,
// то с одной этой переменной можно работать с разных файлов, даже если она там не определена,
// и если ее изменить, она изменится везде на глобальном уровне

// "local" static - статичекская переменная в теле функции
void foobar(int c)
{
    // ЭТО ЛОКАЛ СТАТИК, эта переменная живет пока работает программа,
    // инициализируется при первом вызове функции и главное сохраняет значение между вызовами функции

    static int a = 0;
    ++a; // типо при 1м вызове а = 1, при втором а = 2 и так далее
    int b = a + c;
}

///////////////////////////////////// UNION

// унион это типо структруа где можно хранить память актуальную инфу только в одном из полей
// имеет размер максимального типа данных в унион (инт чар и тп)

// [aaaa|bbbb|cccc]

struct Test1
{
    int a;   // 4 byte
    int b;   // 4 byte
    float c; // 4 byte
}; // 12 bytes

// [****]

union Test1Union
{
    int a;
    int b;
    float c;
}; // 4 bytes

struct ListNodeA
{
    std::string imya;
    ListNodeA *next;
};

struct ListNodeB
{
    int telefon;
    ListNodeB *next;
};

struct ListNodeC
{
    float zarplata;
    ListNodeC *next;
};

struct UniversalList
{
    char type = 0; // то с какой "буквой мы работаем" т.е. с каким из 3х списков
    union
    {
        char omg; // будет выводить ОШИБОЧНО в чар кусок памяти первого байта указателя !!
        int omgint;
        ListNodeA *nextA; // мы можем доступиться только в 1 из списков
        ListNodeB *nextB;
        ListNodeC *nextC;
    }; // 8 байтов (1 указатель - 8 байт)

    // ListNodeC myC;
    // UniversalList a;
    // a.nextC = &myC; // 0xFFFFFFFAA;
    // char omgChar = a.omg; // 0xAA;
    // int omgInt = a.omgint; // 0xFFAA;
};

///////////////////////////////////////////////
////////// ИНДЕКСНЫЙ СПИСОК L1v //////////////////

// было так

// struct IntListNode // ноде - это элемент списка, список это куча объектов структуры,
// // каждый из которых содержит указатель на следующий элемент
// {
//     int value = 0;               // значение этого элемента списка
//     IntListNode *next = nullptr; // указатель на следующий элемент списка
// };
// struct IntList
// {
//     IntListNode *head = nullptr; // указатель на начало списка
// };

// а стало:

struct List1IdxNode
{
    int value = 0; // значение этого элемента списка
    int nextIdx = -1;
};

struct List1Idx
{
    static const int MAX_ELEMENTS = 100;
    List1IdxNode elements[MAX_ELEMENTS]; // статический массив из элементов индексного списка
    int headIdx = -1;                    // индекс головы
    int freeIdx = -1;                    // индекс первого свободного элемента

    List1Idx() // конструктор инициализирует элементы чтобы сформировать пустой индексный список
    {
        for (int i = 0; i < MAX_ELEMENTS - 1; ++i)
        {
            elements[i].nextIdx = i + 1;
        }
        elements[MAX_ELEMENTS - 1].nextIdx = -1;
        freeIdx = 0;
    }

    void AddToTail(int value)
    {
        if (freeIdx != -1) // если в свободном списке что-то есть
        {
            int newElementIdx = freeIdx;               // индекс нового элемента (голова свободного списка)
            freeIdx = elements[newElementIdx].nextIdx; // новая свободная голова - то куда указывала старая свободная голова (может быть -1)
            elements[newElementIdx].value = value;     // заполнили значение
            if (headIdx == -1)                         // если головы заполненного не было - новый это будет голова
                headIdx = newElementIdx;
            else
            {
                // иначе пройдем по заполненному списку до хвоста - элемента у которого некст это -1
                int nextIdx = elements[headIdx].nextIdx;
                while (nextIdx != -1 && elements[nextIdx].nextIdx != -1)
                    nextIdx = elements[nextIdx].nextIdx;
                elements[nextIdx].nextIdx = newElementIdx; // старому хвосту в некс запишем только что выделенный элемент с новым значением, он станет новым хвостом
            }
            elements[newElementIdx].nextIdx = -1; // только что выделенный элемент - новый хвост, некст у него -1
        }
    }
};

///////////////////////////////////////////////

// СТРОКИ StrL StrM

// STR_L
struct StrL
{
    static const int N = 10;

    char str[N];
    int len = 0;
};

// STR_M
struct StrM
{
    static const int N = 10;
    char str[N+1];
    char Mark;
};

//2. Заменить в строке все включения заданной буквы на другую букву.

//StrL
void strL_2(StrL &stroka, char a, char b)
{
    for(int i=0; i < stroka.len; i++)
    {
        if(stroka.str[i]== a)
            stroka.str[i]=b;
    }
}

void strM_2(StrM stroka, char a, char b)
{
    int i =0;
    while(stroka.str[i] != stroka.Mark)
    {
        if(stroka.str[i]== a)
            stroka.str[i]=b;

        i++;
    }

}
