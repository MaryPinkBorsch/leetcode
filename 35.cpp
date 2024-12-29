#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
        int mid = (l + r) / 2;

        while (l < r) {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
            mid = (l + r) / 2;
        }
        if (nums[l] < target)
            return l + 1;
        else
            return l;
    }
};

int main(int argc, char * argv[]) 
{
    Solution wtf;
    std::vector<int> tmp = {1,3,5,6};
    auto res = wtf.searchInsert(tmp,5);
    return 0;
}
