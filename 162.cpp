// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {

//         int s = nums.size() - 1;
//         if (s == 0)
//             return 0;
//         if (nums[0] > nums[1])
//             return 0;
//         if (nums[s] > nums[s - 1])
//             return s;

//         for (int i = 1; i < s; i++) {
//             if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
//                 return i;
//         }

//         return -1;
//     }
// };

//https://leetcode.com/problems/find-peak-element/?envType=study-plan-v2&envId=leetcode-75