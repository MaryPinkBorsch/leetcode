#include <unordered_map> 
#include <iostream>

using namespace std;

class Solution {
public:
    unordered_map <int, int> memo;
    int tribonacci(int n) 
    {

        std::cout << "Calculating for " << n << std::endl;

        if(n==0)
            return 0;
        
        if(n==1||n==2)
            return 1;

        
        auto it = memo.find(n);
        if(it != memo.end())
            return it->second;
        else 
        {
            memo[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
            return memo[n];
        }

    }
};

class SolutionBad {
public:
    int tribonacci(int n) 
    {
        std::cout << "Calculating for " << n << std::endl;
        if(n==0)
            return 0;
        
        if(n==1||n==2)
            return 1;

        
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);

    }
};


int main(int argc, char * argv[]) 
{
    Solution omg;
    omg.tribonacci(10);
    return 0;
}