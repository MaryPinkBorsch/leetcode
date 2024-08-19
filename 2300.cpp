#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        int sum = 0;
        vector<int> res;
        res.resize(spells.size());
        sort(potions.begin(), potions.end());
        for(int i =0; i <spells.size(); i++)
        {
            sum =0;
            bool y =false;
            for(int j = 0; j < potions.size(); j++)
            {
                auto s = (potions[j])*spells[i];
                //if(y==0 && (potions[j]*spells[i] >= success))
                if(s>=success && y==0)
                    y = true;
                
                if(y)
                    res[i]++;

                
            }
        }
        return res;



        
    }
};

int main()
{

    Solution w;

    vector<int> s = {5,1,3}; vector<int> p = {1,2,3,4,5};
    long long suc = 7;
    
     w.successfulPairs(s, p, suc);
    return 0;
}