
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // конструктор для структуры
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *res = root;
        while (res != nullptr)
        {
            if (res->val == val)
                break;
            else if (res->val > val)
                res = res->left;
            else if (res->val < val)
                res = res->right;
        }
        return res;
    }
};

int main(int argc, char * argv[])
{

    TreeNode * root = new TreeNode(4); // кладем 4 в корень, в его значение вал
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Solution tmp;
    tmp.searchBST(root, 2);


    return 0;
}