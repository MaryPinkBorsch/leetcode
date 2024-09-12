#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    Solution() // ЧИТ ДЛЯ СКОРОСТИ!!!!!!!!
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        unordered_set<int> visited;
        vector<int> path;
        path.reserve(n);
        int res = 0;
        visited.insert(0);
        path.push_back(0);
        // нам надо чтоб всегда дорога ВХОДИЛА в город в jопе стека,
        // а не выходила

        unordered_map<int, unordered_set<int>> connections_map; // существующие связи
        unordered_map<int, unordered_set<int>> connections_bi_map;
        for (auto &connection : connections)
        {
            connections_map[connection[0]].insert(connection[1]);
            connections_bi_map[connection[0]].insert(connection[1]);
            connections_bi_map[connection[1]].insert(connection[0]);
        }

        while (visited.size() != n)
        {
            bool tupik = true;
            // back в массиве = top в стеке
            int top = path.back();

            for (auto &other_city : connections_bi_map[top])
            {
                if (visited.find(other_city) == visited.end())
                {
                    tupik = false;
                    // типо дорога идет не в ту сторону
                    if (connections_map.find(other_city) == connections_map.end() || connections_map[other_city].find(top) == connections_map[top].end())
                        res++;
                    visited.insert(other_city);
                    path.push_back(other_city);
                    break;
                }
            }
            if (tupik)
                path.pop_back();
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution omg;
    std::vector<std::vector<int>> wtf = {{1,0},{2,0}};
    auto res = omg.minReorder(3,wtf);
    return 0;
}