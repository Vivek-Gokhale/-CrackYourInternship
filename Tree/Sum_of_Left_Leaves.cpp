
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

    void Helper(TreeNode *root, int &sum, bool flag)
    {
        if(root == nullptr)return;
        if(root->left == nullptr && root->right == nullptr && flag) sum += root->val;
        Helper(root->left, sum, true);
        Helper(root->right, sum, false);

    }
    int sumOfLeftLeaves(TreeNode* root) {
         int sum = 0;
        // Helper(root, sum, false);
        // return sum;
        
        queue<pair<TreeNode*, bool>> tree;
        tree.push({root, false});
        while(!tree.empty())
        {
            auto it = tree.front();
            tree.pop();
            if(it.first->left == nullptr && it.first->right == nullptr && it.second == true)
            {
                sum += it.first->val;
            }
            if(it.first->right != nullptr)
            tree.push({it.first->right, false});
            if(it.first->left != nullptr)
            tree.push({it.first->left, true});
        }
        return sum;
    }
};