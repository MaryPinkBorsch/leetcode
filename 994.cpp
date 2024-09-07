#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    struct orange
    {
        int x = -1;
        int y = -1;
    };
    int orangesRotting(vector<vector<int>> &grid)
    {
        int res = 0;
        vector<orange> front;
        // int i =0; int j =0;
        bool has_orange = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    orange tmp;
                    tmp.x = i;
                    tmp.y = j;
                    front.push_back(tmp);
                }
                if (grid[i][j] == 1)
                    has_orange = 1;
            }
        }
        if (front.empty() && has_orange)
            return -1;

        if (front.empty() && !has_orange)
            return 0;

        if (!front.empty() && !has_orange)
            return 0;
        while (!front.empty())
        {

            vector<orange> next_front;

            for (int i = 0; i < front.size(); i++)
            {

                // слева ячейка
                if (front[i].y != 0 &&
                    grid[front[i].x][front[i].y - 1] == 1)
                {
                    // rotten = 1;
                    orange tmp;
                    tmp.x = front[i].x;
                    tmp.y = front[i].y - 1;
                    grid[tmp.x][tmp.y] = 2;
                    next_front.push_back(tmp);
                }
                // сверху ячейка
                if (front[i].x != 0 &&
                    grid[front[i].x - 1][front[i].y] == 1)
                {
                    orange tmp;
                    tmp.x = front[i].x - 1;
                    tmp.y = front[i].y;
                    grid[tmp.x][tmp.y] = 2;
                    next_front.push_back(tmp);
                }
                // справа
                if (front[i].y != grid[front[i].x].size() - 1 && grid[front[i].x][front[i].y + 1] == 1)
                {
                    orange tmp;
                    tmp.x = front[i].x;
                    tmp.y = front[i].y + 1;
                    grid[tmp.x][tmp.y] = 2;
                    next_front.push_back(tmp);
                }
                // vnis
                if (front[i].x != grid.size() - 1 &&
                    grid[front[i].x + 1][front[i].y] == 1)
                {
                    orange tmp;
                    tmp.x = front[i].x + 1;
                    tmp.y = front[i].y;
                    grid[tmp.x][tmp.y] = 2;
                    next_front.push_back(tmp);
                }
            }
            if (next_front.empty())
                break;
            res++;
            front = next_front;
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return res;
    }
};

class Solution22
{
public:
    int orangesRotting2(vector<vector<int>> &grid)
    {
        int res = 0;
        // vector <int> front;

        bool has_rotten = true;
        while (has_rotten)
        {
            has_rotten = false;
            bool rotten = false;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 0 || grid[i][j] == 1)
                        continue;
                    else if (grid[i][j] == 2)
                    {
                        if (j != 0 && grid[i][j - 1] == 1) // слева ячейка
                        {
                            rotten = 1;
                            grid[i][j - 1] = 2;
                        }
                        if (i != 0 && grid[i - 1][j] == 1) // сверху ячейка
                        {
                            rotten = 1;
                            grid[i - 1][j] = 2;
                        }
                        if (j != grid[i].size() - 1 && grid[i][j + 1] == 1) // справа
                        {
                            rotten = 1;
                            grid[i][j + 1] = 2;
                        }
                        if (i != grid.size() - 1 && grid[i + 1][j] == 1) // vnis
                        {
                            rotten = 1;
                            grid[i + 1][j] = 2;
                        }
                    }
                }
            }
            if (rotten)
            {
                res++;
                has_rotten = rotten;
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    // vector<vector<int>> grid = {{2, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    //                             {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    //                             {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    //                             {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    //                             {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    //                             {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    //                             {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    //                             {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    //                             {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    //                             {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    //   vector<vector<int>> grid = {{2,1,1},{1,1,1},{0,1,2}};
    // vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    // vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 1}, {0, 1, 2}};
    vector<vector<int>> grid = {{2, 2}, {1, 1}, {0, 0}, {2, 0}};
    Solution w;
    w.orangesRotting(grid);
    return 0;
}