// class Solution {
// public:
//     int sumOfUnique(vector<int>& nums) 
//     {
//         unordered_map<int,int> mapp;

//         for(auto& numik : nums)
//         {
//             mapp[numik] += 1;
//         }

//         int res =0;
//         for(auto it = mapp.begin(); it != mapp.end(); it++)
//         {
//             if(it->second == 1)
//                 res += it-> first; 
//         } 
//         return res;
//     }
// };

//https://leetcode.com/problems/sum-of-unique-elements/description/