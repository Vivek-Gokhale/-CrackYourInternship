
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
    bool Helper(TreeNode *rLeft, TreeNode *rRight)
    {
        if(rLeft == nullptr && rRight == nullptr)return true;
        if(rLeft == nullptr || rRight == nullptr)return false;
        if(rLeft->val != rRight->val)return false;
        return (Helper(rLeft->left, rRight->right) && Helper(rLeft->right, rRight->left));
        
    }
    bool isSymmetric(TreeNode* root) {
        return Helper(root->left, root->right);
    }
};