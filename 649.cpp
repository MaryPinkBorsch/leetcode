#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int r = 0;
        int d = 0;
        for (int i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'R')
                r++;
            if (senate[i] == 'D')
                d++;
        }

        while (r != 0 || d != 0)
        {
            for (int i = 0; i < senate.size(); i++)
            {
                if (senate[i] == '0')
                    continue;
                if (senate[i] == 'R')
                {
                    bool found = 0;
                    for (int j = 1 + i; j < senate.size(); j++)
                    {
                        if (senate[j] == 'D')
                        {
                            senate[j] = '0';
                            d--;
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        for (int j = 0; j < i; j++)
                        {
                            if (senate[j] == 'D')
                            {
                                senate[j] = '0';
                                d--;
                                found = 1;
                                break;
                            }
                        }
                    }
                    if (found == 0 && d==0)
                        return "Radiant";
                }

                else if (senate[i] == 'D')
                {
                    bool found = 0;
                    for (int j = 1 + i; j < senate.size(); j++)
                    {
                        if (senate[j] == 'R')
                        {
                            senate[j] = '0';
                            r--;
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        for (int j = 0; j < i; j++)
                        {
                            if (senate[j] == 'R')
                            {
                                senate[j] = '0';
                                r--;
                                found = 1;
                                break;
                            }
                        }
                    }
                    if (found == 0 && r==0)
                        return "Dire";
                }
            }
        }

        if (r != 0)
            return "Radiant";
        if (d != 0)
            return "Dire";

        for (int i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'R')
                return "Radiant";
            if (senate[i] == 'D')
                return "Dire";
        }
        return "";
    }
};

int main()
{
    Solution w;
    string s = "RDRDRDDRDRDRDRDRRDRDRDRDRDRDDDDRRDRDRDRDRDRDRDRRRRRDRDRDRDRDDDDDRDRDRDRDRDRDRDRRDRDRDRDRDRDRRDRDRDRDRDRDRDRDRRDRDRDRDRDRRD";
    cout << w.predictPartyVictory(s);
    return 0;
}