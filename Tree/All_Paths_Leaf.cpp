

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
    void Helper(TreeNode *root, string path, vector<string> &ans)
    {
        if(root == nullptr)return;
        if(root->left == nullptr && root->right == nullptr)
        {
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        path += to_string(root->val);
        path += "->";
        Helper(root->left, path, ans);
       
        
        Helper(root->right, path, ans);
       

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        Helper(root, path, ans);
        return ans;
    }
};