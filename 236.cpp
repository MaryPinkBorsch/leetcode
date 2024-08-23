// TreeNode* search_dfs(TreeNode* cur, int value) // поиск в глубину нормаьный  
//     {
//         if (cur->val == value)
//             return cur;

//         if (cur->left) 
//         {
//             TreeNode* res = search_dfs(cur->left, value);
//             if (res)
//                 return res; // если нижний деть че то нашел , он передаст это
//                             // наверх чтоб не потерять
//         }
//         if (cur->right) 
//         {
//             TreeNode* res = search_dfs(cur->right, value);
//             if (res)
//                 return res; // если нижний деть че то нашел , он передаст это
//                             // наверх чтоб не потерять
//             // в итоге результат выйдет из рекусии и вернут его в мейн функцию
//         }

//         return nullptr;
//     }

// DFS ПОСИК В ГЛУБИНУ (ПОИСК)



///236 (тут вектор как стек)



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */




// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
//     {
//         vector <TreeNode*> putP; // путь от корня dо элемента р
//         vector <TreeNode*> putQ; // путь от корня dо элемента q

//         search_dfs(root, p->val, putP);
//         search_dfs(root, q->val, putQ);
//         int i = 0; 
//         TreeNode* tmp = 0;
//         while(1)
//         {
//             if(i == putP.size() || i == putQ.size()) // если одна нода лежит на пути к другому
//                 return tmp;


//             if(putP[i]==putQ[i])
//             {
//                 tmp = putP[i];
//                 i++;
//             }
//             else 
//                 return tmp;
                         
//         }


//     }

//     TreeNode* search_dfs(TreeNode* cur, int value, vector <TreeNode*> & cur_put) // поиск в глубину нормаьный (со vector для отсдележивания пути)
//     {
//         cur_put.push_back(cur);
//         if (cur->val == value)
//             return cur;

//         if (cur->left) 
//         {
//             TreeNode* res = search_dfs(cur->left, value, cur_put);
//             if (res)
//                 return res; // если нижний деть че то нашел , он передаст это
//                             // наверх чтоб не потерять
//         }
//         if (cur->right) 
//         {
//             TreeNode* res = search_dfs(cur->right, value,cur_put);
//             if (res)
//                 return res; // если нижний деть че то нашел , он передаст это
//                             // наверх чтоб не потерять
//             // в итоге результат выйдет из рекусии и вернут его в мейн функцию
//         }


//         cur_put.pop_back(); //  типо мы ниче не нашли и идум обратно
//         return nullptr;
//     }
// };