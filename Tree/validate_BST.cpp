
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool Helper(TreeNode* root, TreeNode *low, TreeNode *high)
    {
        if(root == nullptr)return true;
        if((low && root->val <= low->val) || (high && root->val >= high->val))
        return false;

        return Helper(root->left, low, root) && Helper(root->right, root, high);
    }
    bool isValidBST(TreeNode* root) {
       return Helper(root, nullptr, nullptr); 
    }
};