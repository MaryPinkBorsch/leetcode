#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &nums)
    {
        bool sorted = false;
        while (!sorted)
        {
            sorted = true;
            for (int i = 0; i < nums.size() - 1; ++i)
            {
                if (nums[i] > nums[i + 1])
                {
                    sorted = false;
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
    }
    void moveZeroes(vector<int> &nums)
    {
        bool stop = true;
        while (1)
        {
            stop = true;

            for (int i = nums.size() - 1; i > 0; i--)
            {

                if (nums[i - 1] == 0 && nums[i] != 0)
                {
                    swap(nums[i - 1], nums[i]);
                    stop = false;
                }
            }
            if (stop == true)
                break;
        }
    }
};

int main()
{
    vector<int> nums = {0, 0, 1};
    Solution w;
    w.moveZeroes(nums);

    return 0;
}

class Solution3 {
public:
    void bubbleSort(vector<int>& nums) {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] > nums[i + 1]) {
                    sorted = false;
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
    }


    void moveZeroes(vector<int>& nums) 
    {
        int sin = 0;
        int krasn = 0;

        while(true)
        {
            while(sin < nums.size() && nums[sin]==0) // сдвинуть синюю стрелку до НЕнуля
                sin++;
            if(sin>= nums.size())
                break; 
            nums[krasn] = nums[sin];
            krasn++;
            sin++;
            if(sin>= nums.size())
                break;            
        }
        for( int i = krasn; i <  nums.size(); i++)
            nums[i] = 0;
    }



    void moveZeroes2(vector<int>& nums) {
        bool stop = true;
        while (1) 
        {
            stop = true;

            for (int i = nums.size() - 1; i > 0; i--) 
            {
                
                if (nums[i - 1] == 0 && nums[i] != 0)
                { 
                    swap(nums[i - 1], nums[i]);
                    stop = false;
                }
            }
            if(stop == true)
                break;
        }
    }
};