
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == nullptr)return ans;
    int lvl = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        int siz = q.size();
        vector<int> level(siz);
        int idx;
        for(int i=0; i<siz; i++)
        {
            auto it = q.front();
            q.pop();
            if(lvl % 2 == 0)
            idx = i;
            else 
            idx = siz - 1 - i;
            level[idx] = it->val;
            if(it->left)
            q.push(it->left);
            if(it->right)
            q.push(it->right);
        }
        ans.push_back(level);
        lvl++;
    } 
    return ans;   
    }
};