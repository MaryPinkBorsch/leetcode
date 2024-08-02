#include <vector>
// #include <algorithm>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int cur = 0; // cur size of window
        int max = 0;
        int zeros = 0; // skolko moshno ehe nuley

        int start = 0;

        if (nums.size() == 1)
            return 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cur++;
                continue;
            }
            if (nums[i] == 0 && zeros < k)
            {
                cur++;
                zeros++;
                continue;
            }
            else if (nums[i] == 0 && zeros >= k)
            {
                if (cur > max)
                    max = cur;

                if (start == nums.size() - 1)
                    break;
                start++;
                i = start;
                cur = 0;
                zeros = 0;
                if (nums[start] == 1)
                    cur++;
                // while (nums[i + 1] != 1 && i < nums.size() - 1)
                // {
                //     i++;
                // }
                // zeros = 0;
                // if (nums[i] == 0)
                // {
                //     if (zeros < k)
                //     {
                //         cur = 1;
                //         zeros = 1;
                //     }
                //     else
                //         cur = 0;
                // }
            }
        }
        if (cur > max)
            max = cur;
        return max;
    }
};

int main()
{
    Solution w;
    int res = 0;

    {
        int k = 0;
        vector<int> nums = {0, 1, 1};
        res = w.longestOnes(nums, k);
    }
    {
        int k = 2;
        vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
        res = w.longestOnes(nums, k);
    }

    {
        int k = 3;
        vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
        res = w.longestOnes(nums, k);
    }

    return 0;
}