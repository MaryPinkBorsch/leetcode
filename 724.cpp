// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) 
//     {
//         vector<int> prefix;
//         vector<int>postfix;
//         prefix.resize(nums.size());
//         postfix.resize(nums.size());
//         prefix[0]=0;
//         postfix[nums.size()-1] =0;
//         for(int i = 1; i < nums.size();i++)
//         {
//             int sum = 0;
//             for(int j = 0; j < i; j++)
//             {
//                 sum+=nums[j];
//             }
//             prefix[i] = sum;
//         }

//         for(int i =0; i <nums.size()-1; i++)
//         {
//             int sum = 0;
//             for(int j = i+1; j < nums.size(); j++)
//             {
//                 sum+=nums[j];
//             }
//             postfix[i] = sum;
//         }
//         for(int i =0; i <nums.size(); i++)
//         {
//             if(prefix[i]==postfix[i])
//                 return i;
//         }

//         return -1;


        
//     }
// };

//https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan-v2&envId=leetcode-75