// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
//     {
//         unordered_set <int> map1;
//         unordered_set <int> map2;
//         vector<vector<int>> ans;
//         ans.resize(2);

//         for(int i =0; i < nums1.size(); i++)
//         {
//             map1.insert(nums1[i]);
//         }

//         for(int i =0; i < nums2.size(); i++)
//         {
//             map2.insert(nums2[i]);
//         }

//         for(auto it = map1.begin(); it != map1.end(); it++)
//         {
//             if(map2.find(*it) == map2.end()) // смотрим есть ли значение из нумс1 в нумс2
//                 ans[0].push_back(*it);
//         }

//         for(auto it = map2.begin(); it != map2.end(); it++)
//         {
//             if(map1.find(*it) == map1.end())
//                 ans[1].push_back(*it); // смотрим есть ли значение из нумс2 в нумс1
//         }

//         return ans;
//     }
// };

// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/