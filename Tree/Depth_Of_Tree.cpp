

#include <bits/stdc++.h>
using namespace std;
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
    int Helper(TreeNode *root)
    {
        if(root == nullptr)return 0;
        int leftDepth =  Helper(root->left);
        int rightDepth =  Helper(root->right);
        return max(leftDepth, rightDepth) + 1;
    }

    int maxDepth(TreeNode* root) {
        return Helper(root);
    }
};