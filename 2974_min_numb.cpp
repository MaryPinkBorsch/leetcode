#include <vector>
#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) 
    {
        for (int j = 0; j < nums.size(); j += 2) 
        {
            int min1 = INT_MAX, min1idx = -1, min2 = INT_MAX, min2idx = -1;
            for (int i = j; i < nums.size(); ++i) 
            {
                if (nums[i] <= min1 && i != min1idx) 
                {
                    min2 = min1;
                    min2idx = min1idx;
                    min1 = nums[i];
                    min1idx = i;
                }
                else if(nums[i] <= min2 && i != min2idx) 
                {
                    min2 = nums[i];
                    min2idx = i;
                }
            }
            std::swap(nums[j], nums[min2idx]);
            if (j == min1idx)
                min2idx = min1idx;
            if (!(j == min1idx && j+1 == min2idx))
                std::swap(nums[j+1], nums[min1idx]);
        }
        return nums;
    }
};

class Solution1 {
public:
    vector<int> numberGame(vector<int>& nums) 
    {
        vector<int> res;
        while (nums.size() != 0)
        {
            int min1 = nums[0];
            int Aliceidx = 0;


            for (int i = 0; i < nums.size(); i++)
            {
                if(nums[i]< min1)
                {
                    Aliceidx = i;
                    min1 = nums[i];
                }
            }
            nums.erase(nums.begin()+Aliceidx);

            int min2 = nums[0];
            int Bobidx = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if(nums[i]< min2)
                {
                    Bobidx = i;
                    min2 = nums[i];
                }
            }
            nums.erase(nums.begin()+Bobidx);

            res.push_back(min2);
            res.push_back(min1);            
        }
        return res;
    }
};

int main(int argc, char* argv[]) 
{
    {
        Solution wtf;
        std::vector<int> tmp = {5,4,2,3};
        auto res = wtf.numberGame(tmp);
    }
    {
        Solution wtf;
        std::vector<int> tmp = {2,5,3,8};
        auto res = wtf.numberGame(tmp);
    }
    return 0;
}