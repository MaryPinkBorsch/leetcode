
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
	int  numIdenticalPairs(vector<int>& nums) {
		int result = 0;

		for (int i = 0; i < nums.size(); i += 1)
		{
			for (int j = 0; j < nums.size(); j += 1)
			{
                if ((nums[i] == nums[j]) && (i< j))
                {
                    result +=1;
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
    auto res = wtf.numIdenticalPairs(tmp);
    return 0;
}