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
//     int longestZigZag(TreeNode* root) {
//         int max = 0;
//         if (!root || (!root->left && !root->right))
//             return 0;
//         dfs(root, max, '0', 0);
//         return max + 1;
        
//     }
//     void dfs(TreeNode* cur, int & max, char prev, int zzs) 
//     {
//         if (zzs > max)
//             max = zzs; // длина текущего зигзага

//         if (cur->left)
//             dfs(cur->left, max, 'l', prev == 'r' ? zzs + 1 : 0 ); // если есть левый деть и мы пришли справа, то ззс++ иначе обнуление ззс
//         if (cur->right)
//             dfs(cur->right, max, 'r', prev == 'l' ? zzs + 1 : 0 ); // если есть правый деть и мы пришли слева, то ззс++ иначе обнуление ззс (зигзаг прервался)
//     }
// };


//https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75