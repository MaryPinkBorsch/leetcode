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
// public:
//     int maxDepth(TreeNode* root) {
//         TreeNode* cur = root;
//         int max = 0; // максимальная высота

//         int num = 0; // текущая высота
//         if(!cur)
//             return 0;
//         maxDepthRecursive(cur, max, num);
//         return max;
//     }

//     void maxDepthRecursive(TreeNode* cur, int & max, int & num)
//     {
//         num++;
//         if(max<num)
//             max = num;

//         if(cur->left)
//             maxDepthRecursive(cur->left, max, num);
//         if(cur->right)
//             maxDepthRecursive(cur->right, max, num);

//         --num;
//     }

//     // int numberNodes(TreeNode* cur)
//     // {
//     //     int res = 1;
//     //     if(cur->left)
//     //         res += printRecursive(cur->left);
//     //     if(cur->right)
//     //         res += printRecursive(cur->right);
//     //     return res;
//     // }

// };

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75