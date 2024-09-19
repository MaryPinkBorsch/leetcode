// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) 
//     {
//         vector<int> dp; // расчет стоимости пути от этой ступени до вершины
//         dp.resize(cost.size()+1);
//         const int N = cost.size();
//         dp[N]=0;
//         dp[N-1] = cost[N-1]; // чтобы не вылететь за границы (начнем с Н-2) 
//         for(int i = N-2; i>=0; i--)
//         {
//             dp[i] = cost[i] + min(dp[i+1], dp[i+2]); // мы спускаемся с лестницы и записываем минимальную цену, которую надо заплатить чтоб подняться с этой ступени до вершины
//         }  
//         return min(dp[0], dp[1]);
//     }
// };

//https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan-v2&envId=leetcode-75