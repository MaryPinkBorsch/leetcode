// class Solution {
// public:
//     vector<int> countBits(int n) 
//     {
//         vector<int> res;
//         res.resize(n+1);
//         for(int i = 0; i < n+1; i++)
//         {
//             int cur = i;
//             while(cur!=0)
//             {
//                 res[i]+=cur%2;
//                 cur=cur/2; //остаток уже посчитали выше строкой
//             }
//         }
//         return res;
        
//     }
// };

//https://leetcode.com/problems/counting-bits/description/?envType=study-plan-v2&envId=leetcode-75