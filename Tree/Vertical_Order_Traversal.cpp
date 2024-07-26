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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    
    vector<vector<int>> ans;
    if(root == nullptr)return ans;    
    map<int, map<int, multiset<int>>> umap;
    queue<pair<TreeNode *, pair<int, int>>> q; //node with vertical and row
    q.push({root, {0, 0}});
    while(!q.empty())
    {
        
            TreeNode *node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            umap[col][row].insert(node->val);
            if(node->left)
            q.push({node->left, {row+1, col-1}});
            if(node->right)
            q.push({node->right, {row+1, col+1}});
        
    }
    for(auto outMp : umap)
    {
        vector<int> vLevel;
        for(auto inMp : outMp.second)
        {
            vLevel.insert(vLevel.end(), inMp.second.begin(), inMp.second.end());
        }
        ans.push_back(vLevel);

    }
return ans;
    }
};