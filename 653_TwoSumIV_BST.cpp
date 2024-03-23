//Definition for a binary tree node.
struct TreeNode 
{
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = root;
        while (res != nullptr) {
            if (res->val == val)
                break;
            else if (res->val > val)
                res = res->left;
            else if (res->val < val)
                res = res->right;
        }
        return res;
    }
    bool rekursia(TreeNode* cur, TreeNode*& root, int & k) 
    {
        if (cur == nullptr)
            return false;
        auto found = searchBST(root, k - cur->val);
        if(found != nullptr && found != cur) // если ищется число, которое равно половине искомого числа КУР
        // чтоб оно не вернуло один элемент дважды
        {
            return true;
        }
        return rekursia(cur->left, root, k) || rekursia(cur->right, root, k);
    }
    bool findTarget(TreeNode* root, int k)
    {
        return rekursia(root, root, k);
    }
};

int main(int arc, char * argv[]) 
{
    TreeNode * root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution tmp;
    tmp.findTarget(root, 28);

    return 0;
}