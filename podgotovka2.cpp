#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>

int AAAOMG = 5;

using namespace std;
namespace MASYA
{
    int AAAOMG = 5;
    void foobar() 
    {
        AAAOMG = 10;
    }
}
void test(int value, int *p_value, int &ref_value)
{
    MASYA::AAAOMG = 6;
    ::AAAOMG = 7;
    value = 1;
    *p_value = 2;
    ref_value = 3;
}

struct dot
{
    // этот метод можно будет использговать так
    // dot A, B;
    // A.x = 1.0;
    // A.y = 1.0;
    // B.x = 2.0;
    // b.y = 2.0;
    // float distance = A.distance_from(B);
    float distance_from(const dot &other)
    {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }

    float x;
    float y;
};

// ОПРЕДЕЛЕНИЕ СПИСКА (пример для чисел, int)

struct IntListNode // ноде - это элемент списка, список это куча указателей указывающих по очеред др на друга
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

// КОНЕЦ штук для списка

int main3(int argc, char *argv[])
{
    // списки из интов
    IntList myList;                // пустой список
    myList.head = new IntListNode; // создали "голову" списка
    myList.head->value = 0;        // доступ к значению первого элемента (голове) по указателю из списка
    // стрелочка это доступ по указателю
    // добавим второй эелемент
    myList.head->next = new IntListNode;
    myList.head->next->value = 1;

    // добавим третий эелемент
    myList.head->next->next = new IntListNode;
    myList.head->next->next->value = 2;

    // НЕУДОБНЕНЬКО!! скоро место кончится на экране
    IntListNode *cur = myList.head->next->next;
    IntListNode *node99 = nullptr;
    for (int i = 0; i < 150; ++i)
    {
        cur->next = new IntListNode;
        cur = cur->next;
        cur->value = 3 + i;
        if (i == 96)
            node99 = cur;
    }

    print_IntList(myList);
    InsertToList(node99, 666);
    cout << endl;
    print_IntList(myList);
    return 0;

    // одномерный массив
    int *p_int = nullptr; // динамический массив это то же что указатель ( 0 == NULL == nullptr )
    p_int = new int[100]; // получение памяти под  100 интов
    p_int[5] = 42;        // доступк к элементу по индексу 5
    delete[] p_int;       // освобождение памяти

    // двумерный массив int-ов, размером 3 на 3
    int **pp_int = nullptr;
    pp_int = new int *[3]; // создаем внешние указатели на 3 массива 1мерных
    for (int i = 0; i < 3; i++)
    {
        pp_int[i] = new int[3]; // циклом задаем память на 3 ячейки к каждому из 1мереных массивов
    }
    pp_int[1][2] = 1; // обращение к массиву по адресу через указатель (например массив индексов: 1 - индекс фигуры, 2 - индекс точки в фигуре)

    for (int i = 0; i < 3; i++)
    {
        delete[] pp_int[i]; // сносим память в обратном порядке (память под внутринние масиивы)
    }
    delete[] pp_int; // сносим память под внешние массиывы

    // статический массив халява, т.к. заранее известны все размеры
    // поэтому компилятор выделяет всю память подряд
    int spp_int[3][3];
    void *pv1 = spp_int;
    void *pv2 = spp_int[0];
    void *pv3 = spp_int[1];
    void *pv4 = spp_int[2];

    // параметры по значению , по указателю и по ссылке
    int a = 10;
    int b = 20;
    int c = 30;
    int *d = &b;
    test(a, &b, c);
    int &e = c;

    // a == 10
    // b == 2
    // c == 3
    e = 40;

    dot aaa;
    aaa.x = 11;
    dot *p_bbb = new dot; // pamyat pod 1 dot (2iy dot bez imeni no na nego est ukasatel p_bbb)
    p_bbb->x = 11;        // dostup k dot "bbb.x" cheres "->"

    int M = 109999;
    char m = M;
    m = (char)M; // pri WARNINGs nado

    // SWITCH
    std::ifstream is;
    char next_char;
    next_char = is.peek();
    switch (next_char)
    {
    case ' ': // пробел
        is >> noskipws >> next_char;
        break;
    case '\r': // перенос строки под виндовс "\r\n", я ненавижу 11ю Винду
        is >> noskipws >> next_char;
        is >> noskipws >> next_char;
        return 0;
    default: // все остальное числа, считываем целиком
        abort();
    }

    // перемотка в начало
    // is.seekg(0);

    // посмотреть след элемнет в потоке
    // next_char = is.peek();

    // ifstream is(filename, ios::in | ios::ate); // открываем файл в конце чтобы проверить его длинну
    //  ios::in - считываем с потока

    // ofstream of(filename, ios::out | ios::trunc);
    // запись в файловый поток
    // перезапись при каждом новом открытии

    // манипуляторы - setw(), setprecision(), skipws no skipws
    // input >> skipws >> tmp.x;
    // input >> noskipws >> tmp.x;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // ДИНАМИЧЕСКИЙ МАССССИВ 1 мерный

    //         int * p_int = nullptr; // динамический массив это то же что указатель на ПЕРВЫЙ элемент (он инициилизировался нулем)
    //     p_int = new int[100]; // получение памяти под  100 интов
    // new возвращает АДРЕС в памяти, где лежит 100 интов
    //     p_int[5] = 42; // доступк к элементу по индексу 5
    //     delete[] p_int; // освобождение памяти

    // ОБРАЩЕНИЕ К ЭЛЕМЕНТАМ ЧЕРЕЗ УКАЗАТЕЛИ И ОПЕР-Р ДОСТУПА К ЭЛЕМЕНТУ []

    //  p_int[i] = 462; // доступк к элементу по индексу i

    // динамический массив это то же что указатель на ПЕРВЫЙ элемент
    // поэтому можно исп-ть арифметику указателей и разыменование " * " для доступа к элементу

    // (p_int + i)              //указатель на Итый элемент
    // *(p_int + i) = 462;     //доступ к Итому элементу через разыменование

    // ДИНАМИЧЕСКИЙ МАССССИВ 2 мерный!!

    //     int ** pp_int = nullptr;
    //     pp_int = new int*[3]; // создаем внешние указатели на 3 массива 1мерных
    //     for (int i =0; i < 3; i++)
    //     {
    //         pp_int[i] = new int[3]; // циклом задаем память на 3 ячейки к каждому из 1мереных массивов
    //     }

    //     pp_int[2][3] = 1; // обращение к массиву по адресу через указатель

    //     *(*(pp_int + 2) + 3) = 1; // обращение к 2mernomu массиву черещз указатели

    //     for (int i =0; i < 3; i++)
    //     {
    //         delete [] pp_int[i];   // сносим память в обратном порядке (память под внутринние масиивы)
    //     }
    //     delete [] pp_int;  // сносим память под внешние массиывы
    //     return 0;
    // }

    // СТАТИЧЕСКИЙ МАССССИВ 2 мерный!!
    float Arr[2][3] = {{1, 2, 3}, {4, 5, 6}}; // !!!!!!!

    static const int NN = 1111;
    int A[NN] = {1, 1, 2};
    // память находится на стеке и пропадет при выходе из области видимости функции

    //  ПЕРЕДАЧА МАССИВОВ В ФУНКЦИИ

    // void calculate_pair_distance(dot *&dots, int &num_dots, float **&distances, int &num_distances)
    //  передача массива в фунцию через ссылку и * (или только через *, просто & нельзя)
    //  передача массива в фунцию осущ-ся через 2 параметра - указатель и длину массива

    // А СТАТИЧЕСКИЕ массивы можно передавать одним параметром:
    // void Foo(int A[6]) - указать конккретную длину
    // ЧЕРЕЗ ССЫЛКУ НЕЛЬЗЯ СТАТИКУ ПЕРЕДАТЬ

    // #include <iostream>
    // void Foo(int A[6])
    // {
    //     A[3] = 5;
    // }
    // int main(int argc, char * argv[])
    // {
    //     int B[6] = {1};
    //     Foo(B);
    //     std::cout<<B[3];

    ////
    return 0;
}
///////////////////////// УКАЗАТЕЛИ НА ФУНКЦИЮ
// это объявление типа указателя на функцию которая работает с элементами вертикальных формуляров
typedef void (*StringFunction)(std::string &toProcess);

// есть две функции которые работают
void toLower(std::string &toProcess)
{
    for (auto &element : toProcess)
    {
        element = std::tolower(element);
    }
}
void toUpper(std::string &toProcess)
{
    for (auto &element : toProcess)
    {
        element = std::toupper(element);
    }
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
};           // 12 bytes

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

enum Cvet
{
    RED = 0,
    GREEN = 1,
    BLUE = 2,
    PINK = 666
};

std::string Cvet2String(Cvet cvet) 
{
    static unordered_map<Cvet, std::string> c2s;
    if (c2s.empty()) 
    {
        c2s[RED] = "Red";
        c2s[GREEN] = "Green";
        c2s[BLUE] = "Blue";
        c2s[PINK] = "Pink";
    }
    return c2s[cvet];
} 

Cvet String2Cvet(std::string cvet) 
{
    static unordered_map<std::string, Cvet> c2s;
    if (c2s.empty()) 
    {
        c2s["Red"] = RED;
        c2s["Green"] = GREEN;
        c2s["Blue"] = BLUE;
        c2s["Pink"] = PINK;
    }
    return c2s[cvet];
} 

int main(int argc, char *argv[])
{
    Cvet moy_lubimy_cvet = (Cvet)666;

    if (moy_lubimy_cvet == PINK) 
    {
        std::cout << "ZELENY" << std::endl;
        std::cout << "PINK " << Cvet::PINK << std::endl;
    }

    std::cout << Cvet2String(PINK) << std::endl;
    std::string novii_cvet = "korichnevii";
    std::cin >> novii_cvet;
    std::cout << (int)String2Cvet(novii_cvet) << std::endl;

    switch (moy_lubimy_cvet) 
    {
        case RED:
        {}
        break;
        case GREEN:
        {}
        break;
        case BLUE:
        {}
        break;
        case PINK:
        {}
        break;
        default:
        break;
    }

    std::cout << " Test1 size is " << sizeof(Test1) << std::endl;
    std::cout << " Test1Union size is " << sizeof(Test1Union) << std::endl;

    Test1 tmp1;
    tmp1.a = 10;
    tmp1.b = 15;

    std::cout << " Test1 a " << tmp1.a << std::endl;
    std::cout << " Test1 b " << tmp1.b << std::endl;

    Test1Union tmp1Union;
    tmp1Union.a = 10;
    tmp1Union.b = 15;

    std::cout << " Test1Union a " << tmp1Union.a << std::endl;
    std::cout << " Test1Union b " << tmp1Union.b << std::endl;
    std::cout << " Test1Union c " << tmp1Union.c << std::endl;

    return 0;
}

int main2(int argc, char *argv[])
{
    std::vector<std::string> text = {"Bubub", "Masya loves cake", "OLOLO"};
    for (auto &theString : text)
        std::cout << theString << std::endl;

    StringFunction myFunction;
    switch (argc)
    {
    case 1:
    {
        myFunction = &toLower;
        break;
    }
    case 2:
    {
        myFunction = &toUpper;
        break;
    }
    }
    for (auto &theString : text)
    {
        (*myFunction)(theString); // ввызов той ыфункции на которую указывакт указатель myFunction с параментом theString
    }
    for (auto &theString : text)
        std::cout << theString << std::endl;



    return 0;}
