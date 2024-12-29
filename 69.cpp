class Solution {
public:
    int mySqrt(int x) 
    {
        long long start = 1;
        while(start*start<=x)
        {
            start +=1;
        }
        return start-1;
        
    }
};