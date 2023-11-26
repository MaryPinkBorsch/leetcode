#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int len = digits.size();
        for (int i = len - 1; i>=0; i--)
        {
            if (digits[i] != 9) 
            {
                digits[i]++;
                break;            
            }
            else
                digits[i] = 0;

            
        }
        if (digits[0] == 0)
        {
            digits.insert(digits.begin(),1);
        } 
        return digits;
    }
};

int main(int argc, char * argv[]) 
{
    Solution wtf;
    std::vector<int> tmp = {1,1,2,2,3,3,4,4};
    auto res = wtf.plusOne(tmp);
    return 0;
}
