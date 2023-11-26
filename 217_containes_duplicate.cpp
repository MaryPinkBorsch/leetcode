#include <unordered_set>
#include <unordered_set>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
     int len = nums.size();
     for (int i = 0; i< len; i++)
     {
        for (int j = i + 1; j< len; j++)
        {
            if (nums[i]==nums[j])
                return true;
        }
     } 

     return false; 
    }
};
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> unique_nums;
        int len = nums.size();
        for (int i = 0; i< len; i++)
        { 
            unique_nums.insert(nums[i]);
        } 
        if (nums.size()==unique_nums.size())
            return false;
        else
            return true; 
    }
};
int main(int argc, char * argv[]) 
{
    Solution wtf;
    std::vector<int> tmp = {42,1,1,2,2,3,3,4,4};
    auto res = wtf.containsDuplicate(tmp);
    return 0;
}