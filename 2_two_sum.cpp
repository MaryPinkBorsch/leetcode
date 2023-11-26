#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
		{
    vector<int> result;
			for (int i = 0; i < nums.size(); ++i)
			{
				for (int k = 0; k < nums.size(); ++k)
				{
					// нужно найти такие i и k что my_ints[i] + my_ints[k] == target
					if (nums[i] + nums[k] == target && i!= k)
					{
						//std::cout << i << " " << k << "\n";
						//std::cout << nums[i] << " " << nums[k] << "\n";
										result.push_back(i);
										result.push_back(k);
										return result;
					}
				}
			}
			return result;
		}
};

int main(int argc, char * argv[]) 
{
    Solution wtf;
    std::vector<int> tmp = {42,1,1,2,2,3,3,4,4};
    auto res = wtf.twoSum(tmp,43);
    return 0;
}