
#include <vector>
// #include <algorithm>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int max = 0;
        int cur = 0;
        int start = 0;
        int zero = 0;

        bool nozero = true;
        bool noone = true;

        if (nums.size() == 1)
            return 0;

        for (int i = 0; i < nums.size(); i++)
        {
            start = i;
            while (i < nums.size())
            {
                if (nums[i] == 0 && zero < 1)
                {
                    zero++;
                    nozero = false;
                    // cur++;
                }
                else if (nums[i] == 0 && zero >= 1)
                {
                    nozero = false;
                    if (cur > max)
                        max = cur;
                    i = start + 1;
                    if (nums[i] == 0)
                    {
                        cur = 0;
                        zero = 0;
                    }
                    else
                    {
                        cur = 1;
                        zero = 0;
                    }

                    break;
                }
                if (nums[i] == 1)
                {
                    cur++;
                    noone = false;
                }

                i++;
            }
            if (cur > max)
                max = cur;
        }
        if (cur > max)
            max = cur;
        if (nozero == true)
            max--;

        if (noone == true)
            return 0;
        return max;
    }
};

int main()
{
    Solution w;
    {
        vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
        w.longestSubarray(nums);
    }
}