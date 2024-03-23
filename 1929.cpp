// class Solution {
// public:
//     vector<int> getConcatenation(vector<int>& nums) 
//     {
//         vector<int> ans ={};
//         int n = nums.size();
//         ans.resize(2*nums.size());
//         for(int i = 0; i<nums.size(); i++)
//         {
//             ans[i]=nums[i];
//             ans[i+n]=nums[i];
//         }
//         return ans;
//     }
// };
