#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST_reqursive(nums, 0, nums.size() - 1);
    }
    TreeNode *sortedArrayToBST_reqursive(vector<int> &nums, int L, int R)
    {
        TreeNode *New_node = new TreeNode();
        
        int mid = L + (R - L) / 2;
        New_node->val = nums[mid];
        if (mid - L == 1)
        {
            New_node->left = new TreeNode(nums[L]);
        }
        else if(mid - L > 1)
        {
            New_node->left = sortedArrayToBST_reqursive(nums, L, mid - 1);
        }

        if (R - mid == 1)
        {
            New_node->right = new TreeNode(nums[R]);
        }
        else if(R - mid > 1)
        {
            New_node->right = sortedArrayToBST_reqursive(nums, mid + 1, R);
        }
        return New_node;
    }
};

int main(int argc, char * argv[])
{
    vector <int> nums = {-10,-3,0,5,9};    
    Solution tmp;
    auto res = tmp.sortedArrayToBST(nums);



    return 0;
}