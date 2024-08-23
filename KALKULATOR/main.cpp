// основано на https://ru.wikipedia.org/wiki/%D0%9E%D0%B1%D1%80%D0%B0%D1%82%D0%BD%D0%B0%D1%8F_%D0%BF%D0%BE%D0%BB%D1%8C%D1%81%D0%BA%D0%B0%D1%8F_%D0%B7%D0%B0%D0%BF%D0%B8%D1%81%D1%8C#%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC

#include <iostream>
#include <unordered_map>
#include <stack>
#include <cctype>
#include <vector>

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

unordered_map<char, int> op_priority;

void print(vector<Element> &to_print) // printit vectori
{
    cout << endl
         << "Вывожу массив " << endl;
    for (int i = 0; i < to_print.size(); i++)
    {
        switch (to_print[i].type)
        {
            case NUMBER:
            {
                cout << to_print[i].number;
                break;
            }
            case OPERATOR:
            {
                cout << to_print[i].op;
                break;
            }
            default:
                abort;
        }
    }
    cout << endl<< endl;
}

int main(int argc, char *argv[])
{
    op_priority['*'] = 2; // круче приоритет и выше и раньше делается
    op_priority['+'] = 1;

    string input; // сохраняем то что нам надо посчитать
    cout << " Введите операцию в калькулятор :) " << endl;
    std::getline(std::cin, input);

    vector<Element> infix_form;

    // первым делом надо из входной строчки получить наши структуры в инфиксной нотации
    for (int i = 0; i < input.size(); i++)
    {
        if (op_priority.find(input[i]) != op_priority.end())
        {
            Element tmp;
            tmp.type = OPERATOR;
            tmp.op = input[i];
            infix_form.push_back(tmp);
        }
        else if (isdigit(input[i]) != 0)
        {
            int j = i + 1;
            while (j != input.size() && isdigit(input[j]) != 0)
                j++; // сдвигаем индекс j до первого символа который не цифра

            // substr вернет подстроку содержащую число, substr.c_str() делает из string char *
            // atoi делает из char * число
            int value = atoi(input.substr(i, j - i).c_str());
            Element tmp;
            tmp.type = NUMBER;
            tmp.number = value;
            infix_form.push_back(tmp);
            i = j - 1; // переставимм И на первый символ после числа (если оно не однозначное а 2значное или тп)
        }
    }
    // надо сделать в другую форму постфиксную (из инфиксной)
    stack<Element> oper_stack;
    vector<Element> postfix_form;
    int i = 0;
    while (i < infix_form.size())
    {
        Element cur = infix_form[i];
        if (cur.type == NUMBER)
            postfix_form.push_back(cur);
        else if (cur.type == OPERATOR)
        {
            while (!oper_stack.empty() && op_priority[oper_stack.top().op] >= op_priority[cur.op]) // пока приоритет того что сверху в стеке >= приоритета знака cur
            {
                postfix_form.push_back(oper_stack.top()); // по алгоритму то что приоритетнее (топ) пихаем в постфикс массив
                oper_stack.pop();                         // выпихиваем нафиг
            }
            oper_stack.push(cur);
        }
        i++;
    }
    while (!oper_stack.empty())
    {
        postfix_form.push_back(oper_stack.top()); // по алгоритму все в массив постфик кладем
        oper_stack.pop();                         // выпихиваем нафиг
    }

    cout << input << endl;
    print(infix_form);
    print(postfix_form);

    return 0;
}