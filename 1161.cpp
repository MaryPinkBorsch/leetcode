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

//     int maxLevelSum(TreeNode* root)  // BFS !!!!!!!!
//     {
//         if(root == nullptr)
//             return 0;
//         vector <int> sums;
//         sums.push_back(0);
//         BFS(root, sums);

//         int lvl = 0;
//         int max = -100001;
        
//         for (int i = 0; i < sums.size(); i++)
//         {
//             if(sums[i]>max)
//             {
//                 max = sums[i];
//                 lvl = i;
//             }
//         }
//         return lvl+1; // тк уровень с 1 начинается а индексация массива с 0
//     }

//     int maxLevelSum1(TreeNode* root)  // DFS !!!!!
//     {
//         if(root == nullptr)
//             return 0;
//         vector <int> sums;
//         int lvl = 0;
//         sums.push_back(0);
//         DFS(root, lvl, sums);

//         int max = -100001;
        
//         for (int i = 0; i < sums.size(); i++)
//         {
//             if(sums[i]>max)
//             {
//                 max = sums[i];
//                 lvl = i;
//             }
//         }
//         return lvl+1; // тк уровень с 1 начинается а индексация массива с 0
//     }
//     void DFS(TreeNode * cur, int lvl, vector <int> & sums)
//     {
//         if(lvl>=sums.size())
//         {
//             sums.push_back(cur->val);
//         }
//         else
//             sums[lvl] += cur->val;

//         if(cur->left)
//         {
//             DFS(cur->left, lvl + 1, sums);
//         }
//         if(cur->right)
//         {
//             DFS(cur->right, lvl + 1, sums);
//         }
//     }

//     void BFS(TreeNode * cur, vector <int> & sums)
//     {
//         std::vector<TreeNode *> front;
//         front.push_back(cur); 
//         int lvl = 0;
//         while(!front.empty()) 
//         {
//             std::vector<TreeNode *> next_front;
//             int sum = 0;
//             for (auto & node : front) 
//             {
//                 sum += node->val;
//                 if (node->left)
//                     next_front.push_back(node->left);
//                 if (node->right)
//                     next_front.push_back(node->right);
//             }
//             if(lvl>=sums.size())
//             {
//                 sums.push_back(sum);
//             }
//             else
//                 sums[lvl] = sum;
//             front = next_front;
//             ++lvl;
//         }
//     }

// };

// //https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75