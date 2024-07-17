// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */

// class Solution {
// public:
//     TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
//     {
//         return search_BT(cloned, target->val);
//     }

//     TreeNode* search_BT(TreeNode* cur, int val_target) // DFS ---> dephs first search (поиск вглубину)
//     {
//         TreeNode* res =nullptr;

//         if(cur->val==val_target)
//             return cur;
//         if (cur->left) // если есть левый деть, идем рекурсивно в него проверять
//         {
//             res = search_BT(cur->left, val_target);
//             if(res) // если тут нашли, то вернем элемент найденный
//                 return res;
            
//         }
//         if(cur->right) // если есть right деть, идем рекурсивно в него проверять
//         {
//             res = search_BT(cur->right, val_target);
//             if(res) // если тут нашли, то вернем элемент найденный
//                 return res;
            
//         }
//         return nullptr;        
//     }


// };

//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/