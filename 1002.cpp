#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        unordered_map<char, int> res;
        for (int i = 0; i < words[0].size(); i++)
        {
            res[words[0][i]]++;
        }

        for (int i = 1; i < words.size(); i++)
        {
            unordered_map<char, int> cur;
            for (int j = 0; j < words[i].size(); j++)
            {
                cur[words[i][j]]++;
            }
            for (auto &itres : res)
            {
                itres.second = std::min(itres.second, cur[itres.first]);
            }
        }
        vector<string> omg;
        for (auto &it : res)
        {
            if (it.second == 0)
                continue;
            string tmp;
            tmp.push_back(it.first);
            for (int k = 0; k < it.second; k++)
                omg.push_back(tmp);
        }
        return omg;
    }
};

int main(int argc, char *argv[])
{
    Solution wtf;
    std::vector<std::string> omg = {"bella", "label", "roller"};
    auto res = wtf.commonChars(omg);
    return res.size();
}