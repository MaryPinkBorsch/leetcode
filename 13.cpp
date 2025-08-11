#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;
string s = "MCMXCIV";

int romanToInt(string s)
{
    unordered_map<char, int> map;
    // unordered_map<string, int> map2;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    // map2['IV'] = 4;
    // map2['IX'] = 9;
    // map2['XL'] = 40;
    // map2['XC'] = 90;
    // map2['CD'] = 400;
    // map2['CM'] = 900;

    int res = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        res += map[s[i]];
        if (i != 0 && (map[s[i]] > map[s[i - 1]]))
        {
            res -= map[s[i - 1]];
            i--;
        }
    }
    return res;
}

int main()
{
    cout << romanToInt(s);
    return 0;
}