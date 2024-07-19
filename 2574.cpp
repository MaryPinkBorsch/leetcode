// class Solution {
// public:
//     vector<int> leftRightDifference(vector<int>& nums)
//     {
//         vector<int> res;
//         res.resize(nums.size());
//         vector<int> L;
//         L.resize(nums.size());
//         vector<int> R;
//         R.resize(nums.size());

//         int Lsum =0;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             L[i] = Lsum;
//             Lsum+=nums[i];
//         }

//         int Rsum = 0;
//         for(int i = nums.size()-1; i >=0; i--)
//         {
//             R[i] = Rsum;
//             Rsum+=nums[i];
//         }

//         for (int i =0; i<  nums.size(); i++)
//         {
//             res[i] = abs(L[i]-R[i]);
//         }
//         return res;
//     }
// };

// https://leetcode.com/problems/left-and-right-sum-differences/description/