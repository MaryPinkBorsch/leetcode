// class Solution {
// public:
//     int maxProductDifference(vector<int>& nums) 
//     {
//         int max =-1; // главгый макс
//         int max2 =-1;
//         int min=11000;  // главный мин
//         int min2 =11001;

//         for(int i =0; i < nums.size(); i++)
//         {
//             if(nums[i]> max)
//             {
//                 max2 = max;                
//                 max = nums[i];
//             }
//             else if(nums[i] > max2)
//             {
//                 max2= nums[i];
//             }

//             if(nums[i] < min)
//             {
//                 min2 = min;
//                 min = nums[i];
//             }
//             else if(nums[i] < min2)
//                 min2 = nums[i];
//         }
//         return ((max * max2) - (min*min2));
//     }
// };

//https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/