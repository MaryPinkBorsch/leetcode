#include <string>
#include <stack>

#include <iostream>

using namespace std;

struct Block
{
    int repeat = 0;
    string prefix = "";
};

class Solution
{
public:
    string decodeString(string s)
    {
        string res = "";
        stack<Block> blocks;
        blocks.push(Block());
        int counter = 0;
        int numberStart = -1;

        while (counter < s.size())
        {
            char symb = s[counter];
            if (isalpha(symb))
            { // string
                if (blocks.empty())
                    blocks.push(Block());
                blocks.top().prefix += symb; // накапливаем префикс текущего элемента на стеке
            }
            else if (isdigit(symb))
            { // number
                if (numberStart == -1)
                { // новое число - новый элемент на стек!
                    blocks.push(Block());
                    numberStart = counter;
                }
            }
            else if (symb == '[')
            {
                // тут кончились цифры числа
                blocks.top().repeat = atoi(s.substr(numberStart, counter - numberStart).c_str());
                numberStart = -1;
            }
            else if (symb == ']')
            {
                string tmp = "";
                for (int i = 0; i < blocks.top().repeat; ++i)
                    tmp += blocks.top().prefix;
                blocks.pop();
                if (blocks.size() != 0)
                    blocks.top().prefix += tmp;
                else
                    res += tmp;
            }
            ++counter;
        }
        if (!blocks.empty())
            res += blocks.top().prefix;
        return res;
    }
};

int main(int argc, char *argv[])
{
    {
        Solution omg;
        string wtf = "3[a]2[bc]";
        std::cout << omg.decodeString(wtf) << std::endl;
    }
    {
        Solution omg;
        string wtf = "3[a2[c]]";
        std::cout << omg.decodeString(wtf) << std::endl;
    }
    {
        Solution omg;
        string wtf = "2[abc]3[cd]ef";
        std::cout << omg.decodeString(wtf) << std::endl;
    }
    {

        Solution omg;
        string wtf = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
        std::cout << omg.decodeString(wtf) << std::endl;
    }
    return 0;
}