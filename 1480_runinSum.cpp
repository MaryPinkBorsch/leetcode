// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) 
//     {
//         int sum = 0;
//         vector<int> res;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             sum += nums[i];
//             res.push_back(sum);
//         }
//         return res;
//     }
// };