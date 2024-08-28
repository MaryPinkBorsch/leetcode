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
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> res;
//         vector<TreeNode*> front;
//         TreeNode* cur = root;
//         if (!cur)
//             return res;

//         front.push_back(root);

//         while (!front.empty()) {
//             vector<TreeNode*> next_front;
//             for (int i = 0; i < front.size(); i++) {
//                 if (front[i]->left)
//                     next_front.push_back(front[i]->left);
//                 if (front[i]->right)
//                     next_front.push_back(front[i]->right);

//                 if (i == front.size() - 1) {
//                     res.push_back(front[i]->val);
//                 }
//             }
//             front = next_front;
//         }
//         return res;
//     }
// };

//https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75