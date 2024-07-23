#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> res;
        res.reserve(nums.size());
        
//         for(int i =0; i < nums.size(); i++)
//         {
//             res[i] = nums[i]*nums[i];
//         }
        
//         sort(res.begin(), res.end());    
        
        
        auto it = lower_bound(nums.begin(), nums.end(), 0);
        int R = distance(nums.begin(), it);
        if (R == nums.size()) // only negative numbers
        {
            for (int i = nums.size()-1; i >= 0; i--)
                res.push_back(nums[i]*nums[i]);
        }
        else if (R == 0) // only positive + 0
        {
            for (int i = 0; i < nums.size(); i++)
                res.push_back(nums[i]*nums[i]);
        }
        else 
        {
            int L = R - 1; 
            while(L >= 0 || R <= nums.size()-1) 
            {
                if (L == -1) 
                {
                    res.push_back(nums[R]*nums[R]);
                    R++;
                }
                else if (R == nums.size()) 
                {
                    res.push_back(nums[L]*nums[L]);
                    L--;
                }
                else 
                {
                    if (abs(nums[L]) < abs(nums[R])) 
                    {
                        res.push_back(nums[L]*nums[L]);
                        L--;
                    }
                    else 
                    {
                        res.push_back(nums[R]*nums[R]);
                        R++;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char * argv[]) 
{
    Solution wtf;
    vector<int> omg = {-4,-1,0,3,10};
    auto res = wtf.sortedSquares(omg);
}