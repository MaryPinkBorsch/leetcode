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
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) 
//     {
//         vector <int> val1;
//         vector <int> val2;
//         DFS(root1, val1);
//         DFS(root2, val2);
//         if(val1 == val2)
//             return true;
//         else
//             return false;
//     }
//     void DFS(TreeNode* cur, vector <int> & massiv)
//     {
//         if(!cur)
//             return;
//         if(!cur->left && !cur->right)
//         {
//             massiv.push_back(cur->val);
//         }
//         if(cur->left)
//             DFS(cur->left, massiv);
//         if(cur->right)
//             DFS(cur->right, massiv);
//     }
// };

//https://leetcode.com/problems/leaf-similar-trees/description/?envType=study-plan-v2&envId=leetcode-75