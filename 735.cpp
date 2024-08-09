#include <vector>
#include <stack>
#include <math.h>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> cosmos;
        for (int i = 0; i < asteroids.size(); i++) 
        {
            if (cosmos.size() == 0) 
            {
                cosmos.push_back(asteroids[i]);
                continue;
            }
             else 
            {
                if ((cosmos.back() > 0 && asteroids[i] > 0) ||
                    (cosmos.back() < 0 && asteroids[i] < 0) || (cosmos.back() < 0 && asteroids[i] > 0)) 
                {
                    cosmos.push_back(asteroids[i]);
                }
                else 
                {   
                    while(cosmos.size() != 0 &&cosmos.back() > 0 && asteroids[i] < 0 )
                    {
                        if (abs(cosmos.back()) == abs(asteroids[i])) 
                        {
                            cosmos.pop_back();
                            break;
                        }
                        if(abs(cosmos.back()) > abs(asteroids[i]))
                            break;
                        if(abs(cosmos.back()) < abs(asteroids[i]))
                        {
                            cosmos.pop_back();
                            if((cosmos.size() != 0 &&cosmos.back() < 0) ||  cosmos.size() == 0)
                                 cosmos.push_back(asteroids[i]);
                        }
                    }
                }
            }
        }
         
        return cosmos;
    }
};

int main()
{
    Solution w;
   // vector <int> astro ={5,10,-5};
   //vector <int> astro ={10,2,-5};
   //vector <int> astro ={-2,-1,1,2};
    //vector <int> astro ={-2,-2,1,-2};
    //vector <int> astro ={-2,1,-2,-2};

    vector <int> astro ={1,-2,-2,-2};
    
    w.asteroidCollision(astro);
    return 0;
}