// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums)
//     {
//         int k = 0;
        
//         int len = nums.size();
//         for(int i = 1; i < len; i++)
//         {
//             if(nums[i] == nums[k])
//                 continue;
//             else
//             {
//                 ++k;
//                 nums[k] = nums[i];
//             }           
//         }
//         return k+1;
//     }
// };