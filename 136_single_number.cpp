#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
/*
    int singleNumber(vector<int>& nums)
    {
        for (int i =0; i<nums.size(); i++)
        {   
            bool found = false;
            for (int j = 0; j<nums.size(); j++ )
            {
                if(nums[i] == nums[j] && i !=j)
                {
                    found = true;
                    break;  
                }            

            }
            if (found == false)
                return nums[i];
        }
        return -1;
    }
*/
    int singleNumber(vector<int>& nums)
    {
        unordered_set<int> seen_numbers;
        for (int i =0; i<nums.size(); i++)
        {
            if (seen_numbers.find(nums[i]) != seen_numbers.end()) 
            {
                seen_numbers.erase(nums[i]);
            }
            else 
            {
                seen_numbers.insert(nums[i]);
            }
        }
        return *seen_numbers.begin();
    }
};

int main(int argc, char * argv[]) 
{
    Solution wtf;
    std::vector<int> tmp = {42,1,1,2,2,3,3,4,4};
    auto res = wtf.singleNumber(tmp);
    return 0;
}