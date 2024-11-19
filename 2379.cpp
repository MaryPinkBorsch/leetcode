#include <iostream>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int start = 0;
        int cur_sum=0;
        int max=0;
        for(int i=0; i < k; i++)
        {
            if(blocks[start+i]=='B')
                cur_sum++;
        }
        max=cur_sum;
        for(int i = 1; i < blocks.size() - k + 1; i++)
        {
            if(blocks[i-1]=='B')
                cur_sum--;
            if(blocks[i+k-1]=='B')
                cur_sum++;
            if(max<cur_sum)
                max=cur_sum;
        }
        if(max>=k)
            return 0;
        else
            return k-max;
    }
};

int main(int argc, char * argv[]) 
{
    int res;
    {
        string wtf = "WBBWWBBWBW";
        Solution omg;
        int k = 7;
        res = omg.minimumRecolors(wtf, k);
    }
    {
        string wtf = "WBB";
        Solution omg;
        int k = 1;
        res = omg.minimumRecolors(wtf, k);
    }
    {
        string wtf = "WWBBBWBBBBBWWBWWWB";
        Solution omg;
        int k = 16;
        res = omg.minimumRecolors(wtf, k);
    }
    {
        string wtf = "BWWWBB";
        Solution omg;
        int k = 6;
        res = omg.minimumRecolors(wtf, k);
    }
    return res;
}

//https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/submissions/1457587572/