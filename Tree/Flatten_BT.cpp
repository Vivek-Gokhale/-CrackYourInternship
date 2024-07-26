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
    void Helper(TreeNode *root, vector<TreeNode*> &preorder)
    {
        if(root == nullptr)return;
       
        preorder.push_back(root);
        Helper(root->left, preorder);
        Helper(root->right, preorder);
    }

    void flatten(TreeNode* root) {
        // vector<TreeNode*> preorder;
        // Helper(root, preorder);
        // int n = preorder.size();
        // for(auto it : preorder)
        // cout << it->val << " ";
        // for(int i=0; i<n-1; i++)
        // {
        //     preorder[i]->left = nullptr;
        //     preorder[i]->right = preorder[i+1];
        // }
        stack<TreeNode*> st;
        if(root == nullptr)return;
        st.push(root);
        TreeNode *temp = nullptr;
        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            
            if(it->right)st.push(it->right);
            if(it->left)st.push(it->left);
            it->left = nullptr;
            if(temp)
            {
                temp->right = it;
                temp = it;
            }
            else
            {
                temp = it;
            }

        }
       
    }
};