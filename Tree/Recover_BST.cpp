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
    TreeNode *first, *last, *middle, *prev;
    void Helper(TreeNode *root)
    {
        if(root == nullptr)return;
        Helper(root->left);
        if(prev != nullptr && root->val < prev->val)
        {
            if(first == nullptr)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }
    
        prev = root;
        Helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = last = middle = prev = nullptr;
        Helper(root);
        if(first && last)
        swap(first->val, last->val);
        else if(first && middle)
        swap(first->val, middle->val);
        
    }
};