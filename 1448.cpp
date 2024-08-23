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


// Solution() // ЧИТ ДЛЯ СКОРОСТИ!!!!!!!!
//     {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//     } 

// ЧИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИИТ!!! (конструктор)

//     int goodNodes(TreeNode* root) 
//     {
//         TreeNode* cur = root;
       
//         int res = 0; // kol-vo good nodes

//         if(!cur)
//             return 0;
//         Recursive(cur, cur->val, res);

//         return res;
        
//     }

//     void Recursive(TreeNode* cur, int max, int & res)
//     {
//         if(cur->val >= max)
//         {
//             res++;
//             max = cur->val;
//         }
    
//         if(cur->left)
//             Recursive(cur->left, max, res);
//         if(cur->right)
//             Recursive(cur->right, max, res);
        
//     }

// };