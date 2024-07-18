// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums)
//     {
//         return recursia(nums, 0, nums.size() - 1);
        
//     }

//     TreeNode* recursia(vector<int>& nums, int L, int R)
//     {
//         int max =-1;
//         int max_idx =-1;

//         for(int i = L; i <= R; i++)
//         {
//             if(nums[i]>max)
//             {
//                 max=nums[i];
//                 max_idx = i;
//             }
//         }
//         TreeNode * res = new TreeNode;
//         res->val = max;

//         if(L!=R)
//         {   
//             if(max_idx != L)
//             {
//                 res->left = recursia(nums, L, max_idx-1);
//             }

//             if(max_idx !=R)
//             {
//                 res->right = recursia(nums, max_idx+1, R);
//             }
//         }
//         return res;    
//     }
// };

//https://leetcode.com/problems/maximum-binary-tree/submissions/1325189731/