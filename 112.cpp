// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
// class Solution {
//     public:
//         bool dfs(int& sum, TreeNode* cur, int targetSum) {
//             sum += cur->val;
//             bool res = false;
//             if (!cur->left && !cur->right) {
//                 if (sum == targetSum) {
//                     res = true;
//                 }
//             }
//             if (cur->left) {
//                 res = dfs(sum, cur->left, targetSum);
//             }
    
//             if (cur->right) {
    
//                 res = res || dfs(sum, cur->right, targetSum);
//             }
//             sum -= cur->val;
    
//             return res;
//         }
//         bool hasPathSum(TreeNode* root, int targetSum) {
//             if (!root)
//                 return false;
//             int summ = 0;
//             return dfs(summ, root, targetSum);
//         }
//     };


//https://leetcode.com/problems/path-sum/