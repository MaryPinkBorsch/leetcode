// class Solution {
// public:
//     int heightChecker(vector<int>& heights) 
//     {
//         vector<int> exp = heights;
//         int res = 0;

//         while(true)
//         {
//             bool sorted = true;
//             for(int i = 0; i < exp.size() - 1;i++)
//             {
//                 if(exp[i]>exp[i+1])
//                 {
//                     swap(exp[i], exp[i+1]);
//                     sorted = false;
//                 }
//             }
//             if(sorted==true)
//                 break;
//         }
//         //sort(exp.begin(), exp.end());

//         for(int i = 0; i < exp.size();i++)
//         {
//             if(exp[i]!=heights[i])
//                 res++;

//         }
//         return res;
        
//     }
// };


//https://leetcode.com/problems/height-checker/description/