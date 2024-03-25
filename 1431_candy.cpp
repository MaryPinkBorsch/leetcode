// class Solution {
// public:
//     vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
//     {
//         // пройти по массиву детей и найти максимум (конфеты)
//         // пройти по массиву детей и прибавляя экстраконфеты сверять с максимумом
//         // если больше макс - ставить тру, иначе фалз

//         vector<bool> res;
//         res.resize(candies.size());
//         int max = -1;
//         for(int i = 0; i <candies.size(); i++)
//         {
//             if(candies[i]>max)
//                 max = candies[i];
//         }

//         for(int i = 0; i <candies.size(); i++)
//         {
//             if(candies[i]+extraCandies >= max)
//                 res[i]=true;
//             else
//                 res[i]=false;
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     int maximumWealth(vector<vector<int>>& accounts) 
//     {
//         int max = -1;
//         for(int i = 0; i < accounts.size(); i++)
//         {
//             int tmp = 0;
//             for(int j = 0; j < accounts[i].size();j++)
//             {
//                 tmp+= accounts[i][j];
//             }
//             if(tmp > max)
//                 max = tmp;
//         }
//         return max;
        
//     }
// };