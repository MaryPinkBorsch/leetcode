#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int p1 = 0;
        int p2 = 1;
        string s;
        int count;
        int newlen = 0;
        if (chars.size() == 1)
        {
            return 1;
        }
        while (p2 < chars.size())
        {
            if (chars[p1] == chars[p2])
            {
                count = 1;
                while (p2 < chars.size() && chars[p1] == chars[p2])
                {
                    p2++;
                    count++;
                }
                s.push_back(chars[p1]);
                newlen++;
                if (count >= 10)
                {
                    string ss = to_string(count);
                    for (int j = 0; j < ss.size(); j++)
                    {
                        s.push_back(ss[j]);
                        newlen++;
                    }
                }
                else if (count > 1)
                {
                    s.push_back((char)count + '0'); // прибавить символ ноль к (количеству) числу = значение счетчика
                    // чтобы получить символ чар = значению счетчика
                    newlen++;
                }
                p1 = p2;
                p2++;
            }
            else
            {
                s.push_back(chars[p1]);
                newlen++;
                p1++;
                p2++;
            }
        }
        if (p1 == chars.size() - 1)
        {
            s.push_back(chars[p1]);
            newlen++;
        }

        chars.resize(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            chars[i] = s[i];
        }

        return newlen;
    }
};

int main(int argc, char *argv[])
{
    {
        Solution wtf;
        std::vector<char> omg = {'a', 'a', 'a', 'a', 'a', 'b'};
        auto res = wtf.compress(omg);
    }
    {
        Solution wtf;
        std::vector<char> omg = {'a', 'b', 'c'};
        auto res = wtf.compress(omg);
    }
    {
        Solution wtf;
        std::vector<char> omg = {'a', 'a'};
        auto res = wtf.compress(omg);
    }
    {
        Solution wtf;
        std::vector<char> omg = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
        auto res = wtf.compress(omg);
    }
    return 0;
}