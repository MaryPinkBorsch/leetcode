#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = -1;
        int end = -1;
        string res;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {

                if (end == -1)
                    end = i;

                if (end != -1 && start == -1)
                {
                    if (i != 0 && s[i - 1] == ' ')
                        start = i;
                    else if (i == 0 && end != -1)
                        start = i;
                    
                    

                    if (end != -1 && start != -1)
                    {
                        if (res.size())
                            res.push_back(' ');

                        for (int k = start; k <= end; k++)
                        {
                            res.push_back(s[k]);
                        }
                        start = -1;
                        end = -1;
                        continue;
                    }
                }

                
            }
        }
        if (end != -1 && start == -1)
        {
            if (res.size())
                res.push_back(' ');

            res.push_back(s[0]);
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution wiw;
    // string s = "the sky is blue";
    string s = "a good   example";
    auto res = wiw.reverseWords(s);

    return 0;
}

//https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75