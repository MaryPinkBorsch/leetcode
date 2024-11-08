// class Solution1 {
// public:
//     int missingNumber(vector<int>& nums) 
//     {
//         sort(nums.begin(), nums.end());
//         if(nums[0]!=0)
//             return 0;
       
//         for(int i =0; i < nums.size()-1; i++)
//         {
//             if(nums[i+1]-nums[i]>1)
//                 return nums[i]+1;

                        
//         }
//         return nums.size();

//     }
// };

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) 
//     {
//         int sum = (nums.size()+1)*nums.size()/2;
//         for(int i =0; i < nums.size();i++)
//         {
//             sum-=nums[i];
//         }
//         return sum;

//     }
// };

//https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=sorting&favoriteSlug=&difficulty=EASY