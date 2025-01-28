#include <vector>
#include <unordered_map>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(nums.size()==1)
            return 0;
        
        unordered_map<int, set<int>> mappa;
        for(int i = 0; i < nums.size();i++)
        {
            auto res = mappa[nums[i]].insert(i);
            {
                auto res_copy = res;
                if ((res_copy.first != mappa[nums[i]].begin()) && ( abs(i - *(--(res_copy.first))) <= k))
                    return true;
            }
            if ((++(res.first) != mappa[nums[i]].end()) && ( abs(i - *(res.first)) <= k))
                return true;
        }
        return false;
    }
};

int main(int argc, char * argv[]) 
{
    Solution omg;
    std::vector<int> wtf = {1,2,3,1,2,3};
    auto res = omg.containsNearbyDuplicate(wtf, 2);
    return res == true ? 1 : 0;
}