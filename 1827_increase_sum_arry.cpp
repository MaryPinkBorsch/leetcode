// class Solution {
// public:
//     int minOperations(vector<int>& nums) 
//     {
//         int sum = 0;
//         for ( int i =1; i < nums.size(); i++)
//         {
//             if(nums[i]<=nums[i-1])
//             {
//                 sum += nums[i-1] + 1 - nums[i];
//                 nums[i] = nums[i-1] + 1;
//             }
//         }
//         return sum;        
//     }
// };

//https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/description/