// основано на https://ru.wikipedia.org/wiki/%D0%9E%D0%B1%D1%80%D0%B0%D1%82%D0%BD%D0%B0%D1%8F_%D0%BF%D0%BE%D0%BB%D1%8C%D1%81%D0%BA%D0%B0%D1%8F_%D0%B7%D0%B0%D0%BF%D0%B8%D1%81%D1%8C#%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC

#include <iostream>
#include <unordered_map>
#include <stack>
#include <cctype>

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

unordered_map<char,int> op_priority;

int main(int argc, char *argv[])
{
    op_priority['*'] = 1; //круче приоритет и выше и раньше делается
    op_priority['+'] = 0;

    string input; // сохраняем то что нам надо посчитать
    cout << " Введите операцию в калькулятор :) " << endl;
    std::getline(std::cin, input);

    stack<Element> infix_form;

    // первым делом надо из входной строчки получить наши структуры в инфиксной нотации
    for(int i =0; i < input.size();i++)
    {
        if(op_priority.find(input[i]) != op_priority.end())
        {
            Element tmp;
            tmp.type = OPERATOR;
            tmp.op = input[i];
            infix_form.push(tmp);
        }
        else if(isdigit(input[i])!=0)
        {
            int j = i+1;
            while(j != input.size() && isdigit(input[j])!=0 )
                j++; // сдвигаем индекс j до первого символа который не цифра

            // substr вернет подстроку содержащую число, substr.c_str() делает из string char *
            // atoi делает из char * число
            int value = atoi(input.substr(i,j-i).c_str()); 
            Element tmp;
            tmp.type = NUMBER;
            tmp.number = value;
            infix_form.push(tmp);
            i=j-1; // переставимм И на первый символ после числа (если оно не однозначное а 2значное или тп)
        }
    }
    
    cout << input << endl;

    return 0;
}