#include <iostream>
#include <stack>

using namespace std;

enum Element_type
{
    NUMBER,
    OPERATOR
};

struct Element
{
    Element_type type; // указывает что содержится в юнион
    union
    {
        double number; // значение числа
        char op;       // операторы хранятся в виде их символа
    };
};

stack<Element> result;
stack<Element> operators;

int main(int argc, char *argv[])
{
    string input; // сохраняем то что нам надо посчитать
    cout << " Введите операцию в калькулятор :) " << endl;
    std::getline(std::cin, input);

    // первым делом надо из входной строчки получить пригодные для обработки последовательность чисел и операторов
    
    // https://ru.wikipedia.org/wiki/%D0%9E%D0%B1%D1%80%D0%B0%D1%82%D0%BD%D0%B0%D1%8F_%D0%BF%D0%BE%D0%BB%D1%8C%D1%81%D0%BA%D0%B0%D1%8F_%D0%B7%D0%B0%D0%BF%D0%B8%D1%81%D1%8C#%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC
    
    cout << input << endl;

    return 0;
}