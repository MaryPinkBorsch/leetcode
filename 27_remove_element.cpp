
#include <unordered_set>
#include <vector>

using namespace std;

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int arrSize = nums.size();
        int counter = 0; // индекс куда надо записать подходящее чмисло
        for (int i = 0; i < arrSize; i++)
        {
            if (nums[i] == val) 
                continue;
            else  
            {
                if (counter != i)
                    nums[counter] = nums[i];
                ++counter;
            }
        }
        return counter;
    }
};

int main(int argc, char * argv[]) 
{
    Solution wtf;
    std::vector<int> tmp = {42,1,1,2,2,3,3,4,4};
    auto res = wtf.removeElement(tmp,2);
    return 0;
}