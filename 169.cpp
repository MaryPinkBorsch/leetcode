// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> mapp;
//         for (auto& numik : nums)
//             mapp[numik]++;
        
//         for (auto& it : mapp) 
//         {
//             if (it.second > nums.size()/2)
//                 return it.first;
//         }
//         return -1;
//     }
// };

//https://leetcode.com/problems/majority-element/description/?envType=problem-list-v2&envId=sorting&favoriteSlug=&difficulty=EASY