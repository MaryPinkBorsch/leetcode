




  struct TreeNode
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                         right(right) {}
  };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // BST = binary search tree - такое дерево где ЛЮБОЙ левый деть всегда
        // меньше родителя а любой правый деть всегда больше родителя лист - нод
        // без детей

        TreeNode* res = root;
        TreeNode* prev = nullptr;

        if (!root)
            return nullptr;

        TreeNode* to_delete = search(root, key, prev);
        if (to_delete) {
            if (!to_delete->left && !to_delete->right) // нету детей
            {
                if (prev == 0) // надо удалить корень
                {
                    res = nullptr;
                }
                if (prev && prev->left == to_delete) // просто занулить
                    prev->left = 0;
                else if (prev && prev->right == to_delete)
                    prev->right = 0;

            } 
            else 
            {
                if (!to_delete->left && to_delete->right) 
                {
                    if (root == to_delete)
                        res = to_delete->right;
                    if (prev && prev->left == to_delete) // просто заменить единственного детя
                        prev->left = to_delete->right;
                    else if (prev && prev->right == to_delete)
                        prev->right = to_delete->right;
                }

                if (to_delete->left && !to_delete->right) {
                    if (root == to_delete)
                        res = to_delete->left;
                    if (prev && prev->left == to_delete) // просто заменить единственного детя
                        prev->left = to_delete->left;
                    else if (prev && prev->right == to_delete)
                        prev->right = to_delete->left;
                }

                if (to_delete->left && to_delete->right) {
                    // всегда заменяем то делит правым ребенком и левого ребенка
                    // с его поддеревом отправляем в крайний левый угол(самого
                    // левого подребенка) правого ребенка
                    TreeNode* tmp = to_delete->right->left; // 6ка на картинке
                    TreeNode* tmp2 = to_delete->left; // на картинке 2ка

                    TreeNode* tmp3 = tmp2; // временная переменная чтобы воткнуть  6ку 
                    
                    while (tmp3->right)
                        tmp3 = tmp3->right;
                    tmp3->right = tmp;

                    if (to_delete == root) 
                    {
                        root = to_delete->right;
                        root->left = tmp2;
                        res = root;
                    }
                    else 
                    {
                        if (prev && prev->left == to_delete) // просто заменить
                        {
                            prev->left = to_delete->right;
                            prev->left->left = tmp2;
                        }
                        else if (prev && prev->right == to_delete) 
                        {
                            prev->right = to_delete->right;
                            prev->right->left = tmp2;
                        }
                    }
                }
            }
        }
        return res;
    }
    TreeNode* search(TreeNode* root, int key, TreeNode*& prev) {
        if (!root)
            return nullptr;
        TreeNode* cur = root;
        prev = nullptr;

        while (1) {
            if (cur->val == key)
                return cur;
            else if (cur->val > key && cur->left) {
                prev = cur;
                cur = cur->left;
            } else if (cur->val < key && cur->right) {
                prev = cur;
                cur = cur->right;
            } else
                return nullptr;
        }
    }
};

  int main(int argc, char * argv[]) 
  {
    {
        // 5,3,6,2,4,null,7
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(6);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        root->right->right = new TreeNode(7);

        Solution wtf;
        wtf.deleteNode(root, 5);
    }

    return 0;
  }