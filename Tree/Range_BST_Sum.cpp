
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
    void Helper(TreeNode* root, int low, int high, int& sum) {
        if (root == nullptr) return;

        // If the current node's value falls within the range, add it to the sum
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
        
        // Recursively process left subtree if there could be nodes within the range
        if (root->val > low) {
            Helper(root->left, low, high, sum);
        }

        // Recursively process right subtree if there could be nodes within the range
        if (root->val < high) {
            Helper(root->right, low, high, sum);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        Helper(root, low, high, sum);
        return sum;
    }
};