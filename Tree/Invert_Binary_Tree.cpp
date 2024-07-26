
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
     void Helper(TreeNode* root) {
        if (root == nullptr)
            return;
        
        // Swap left and right subtrees
        swap(root->left, root->right);
        
        // Recursively invert left and right subtrees
        Helper(root->left);
        Helper(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
    //  if(root == nullptr)
    //  {
    //     return root;
    //  }   
    //  TreeNode *LEFT = invertTree(root->left);
    //  TreeNode *RIGHT = invertTree(root->right);
    //  root->left = RIGHT;
    //  root->right = LEFT;
    //  return root;
    Helper(root);
return root;
    }
};