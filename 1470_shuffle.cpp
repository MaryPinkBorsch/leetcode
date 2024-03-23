// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) 
//     {
//         vector<int> ans;
//         ans.resize(nums.size());
//         if(n!=nums.size()/2)
//             abort();
//         for (int i = 0; i < n; i++)
//         {
//             ans[2*i] = nums[i];
//             ans[2*i+1] = nums[n+i];
//         }
//         return ans;
        
//     }
// };
