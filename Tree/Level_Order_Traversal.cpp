
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
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> order;
    if(root == nullptr)return order;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        int siz = q.size();
        vector<int> level;
        while(siz--)
        {
            auto it = q.front();
            q.pop();
            level.push_back(it->val);
            if(it->left)
            q.push(it->left);
            if(it->right)
            q.push(it->right);
        }
        order.push_back(level);
    }
    return order;
    }
};