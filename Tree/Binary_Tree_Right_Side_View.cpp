
#include<bits/stdc++.h>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        if(root == nullptr)return result;
        q.push(root);
        while(!q.empty())
        {
            int siz = q.size();
            result.push_back(q.front()->val);
            while(siz--)
            {
                
            auto it = q.front();
            q.pop();
            if(it->right)
            q.push(it->right);
            if(it->left)
            q.push(it->left);
            }
        }
        return result;
    }
};