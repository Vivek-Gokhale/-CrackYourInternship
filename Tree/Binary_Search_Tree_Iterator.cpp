

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
 
class BSTIterator {
public:
    vector<int> inorder;
    int idx;
    BSTIterator(TreeNode* root) {
        idx = 0;
        Helper(root, inorder);
    }
    void Helper(TreeNode *root, vector<int> &inorder)
    {
        if(root == nullptr)return;
        Helper(root->left, inorder);
        inorder.push_back(root->val);
        Helper(root->right, inorder);
    }
    
    int next() {
        if(hasNext())
        return inorder[idx++];
        return -1;
    }
    
    bool hasNext() {
        if(idx < inorder.size())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */