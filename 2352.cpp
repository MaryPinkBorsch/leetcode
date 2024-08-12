#include <vector>
#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            bool ravno = true;
            for (int j = 0; j < grid.size(); j++)
            {
                ravno = true;
                for (int k = 0; k < grid.size(); k++)
                {
                    if (grid[i][k] != grid[k][j])
                        ravno = false;
                }
                if (ravno == true)
                    res++;
            }
        }
        return res;
    }
};

int main()
{

    Solution w;

    vector<vector<int>> grid{{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    // grid = [ [ 3, 2, 1 ], [ 1, 7, 6 ], [ 2, 7, 7 ] ];
    //  grid {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    int r = w.equalPairs(grid);
    return r;
}