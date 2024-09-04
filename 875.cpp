#include <vector>
using namespace std;

class Solution {
public:
    int timeToEatEverything(vector<int>& piles, int k) 
    {
        int res = 0;
        for (auto & pile : piles) 
        {
            res += pile/k;
            if (pile%k)
                ++res;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];
        for (auto & pile : piles)
            if (pile > max)
                max = pile;

        int L = 1;
        int R = max;
        int mid = L + (R - L)/2;
        int min_k = max;
        while(L<=R) 
        {
            int time_to_eat = timeToEatEverything(piles, mid);
            if (time_to_eat > h)
            {
                if (L == mid)
                    L = mid + 1;
                else
                    L = mid;
                mid = L + (R - L)/2;
            }
            else if (time_to_eat <= h)
            {
                // коко успела бы сожрать все бананы со скоростью mid
                // если это медленнее прошлого минимума - запишем минимум
                if (mid < min_k) 
                    min_k = mid;
                if (R == mid)
                    R = mid - 1;
                else
                    R = mid;
                mid = L + (R - L)/2;
            }
        }
        return min_k;
    }
};

int main(int argc, char * argv[]) 
{
    int res = 0;
    {
        Solution wtf;
        std::vector<int> omg = {3, 6, 7, 11};
        res = wtf.minEatingSpeed(omg, 8);
    }
    {
        Solution wtf;
        std::vector<int> omg = {30,11,23,4,20};
        res = wtf.minEatingSpeed(omg, 5);
    }
    
    return res;
}

