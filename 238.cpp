// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) 
//     {
//         vector<int> prefix;
//         vector<int> sufix;
//         prefix.resize(nums.size());
//         sufix.resize(nums.size());

//         int cur = 1;

//         for(int i = 0; i < nums.size(); i++)
//         {
//             prefix[i] = cur*nums[i];
//             cur = prefix[i]; 
//         }
//         // pref: 1 2 6 24
//         cur = 1;
//         for(int i =nums.size() - 1; i >= 0 ; i--)
//         {
//             sufix[i] = cur*nums[i];
//             cur = sufix[i];
//         }
//         // suf: 24 24 12 4
        
//         vector<int> res;
//         res.resize(nums.size());

       
//         for(int i = 0; i < nums.size(); i++)
//         {
//             cur = 1;
//             if(i!=0)
//                 cur*= prefix[i-1];
            
//             if(i!= nums.size() -1 )
//                 cur*= sufix[i+1];
//             res[i] = cur;
//         }
//         return res;
//     }
// };

//https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=leetcode-75