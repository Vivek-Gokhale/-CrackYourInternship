
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
 void Helper(TreeNode* root, vector<int> &inorder)
    {
        if(root == nullptr)return;
        Helper(root->left, inorder);
        inorder.push_back(root->val);
        Helper(root->right, inorder);
    }
    int getMinimumDifference(TreeNode* root) {
         vector<int> inorder;
        Helper(root, inorder);
        int mini = INT_MAX;
        int n = inorder.size();
        for(int i=0; i<n-1; i++)
        {
            mini = min(mini, abs(inorder[i] - inorder[i+1]));
        }
        return mini;
    }
};