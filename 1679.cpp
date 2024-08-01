// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k)
//     {
//         int res = 0;
//         unordered_map<int, int> freq;
//         for (int i =0; i < nums.size();i++)
//         {
//             auto it = freq.find(k - nums[i]);
//             if(it != freq.end())
//             {
//                 res++;
//                 (it->second)--; // это значение частоты появления
//                 if(it->second == 0)
//                     freq.erase(it); // убирает из мапы значение если таких не осталось

//             }
//             else
//             {
//                 freq[nums[i]]++;
//             }
//         }
//         return res;
//     }
// };

// https://leetcode.com/problems/max-number-of-k-sum-pairs/?envType=study-plan-v2&envId=leetcode-75