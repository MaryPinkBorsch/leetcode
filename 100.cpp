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
//         bool dfs(TreeNode* cur, TreeNode* tmp) {
//             bool f1 = true;
//             bool f2 = true;
    
//             if (cur->val != tmp->val)
//                 return false;
//             if ((!cur->left && tmp->left) || (cur->left && !tmp->left))
//                 return false;
//             if (cur->left && tmp->left) {
//                 f1 = dfs(cur->left, tmp->left);
//             }
    
//             if ((!cur->right && tmp->right) || (cur->right && !tmp->right))
//                 return false;
//             if (cur->right && tmp->right) {
//                 f2 = dfs(cur->right, tmp->right);
//             }
    
//             return f1 && f2;
//         }
//         bool isSameTree(TreeNode* p, TreeNode* q) {
//             if (!p && !q)
//                 return true;
//             if ((!p && q) || (p && !q))
//                 return false;
    
//             return dfs(p, q);
//         }
//     };



//https://leetcode.com/problems/same-tree/description/