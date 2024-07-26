#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    void markParent(unordered_map<TreeNode*, TreeNode*> &mp, TreeNode *root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            if(it->left)
            {
                mp[it->left] = it;
                q.push(it->left);
            }
            if(it->right)
            {
                mp[it->right] = it;
                q.push(it->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        markParent(mp, root);
        visited[target] = true;
        int currLevel = 0;
        q.push(target);
        
        while(!q.empty())
        {
            int siz = q.size();
            if(currLevel++ == k) break;
            for(int i = 0; i < siz; i++)
            {
                auto it = q.front();
                q.pop();
                
                if(it->left && !visited[it->left])
                {
                    q.push(it->left);
                    visited[it->left] = true;
                }
                if(it->right && !visited[it->right])
                {
                    q.push(it->right);
                    visited[it->right] = true;
                }
                if(mp[it] && !visited[mp[it]])
                {
                    q.push(mp[it]);
                    visited[mp[it]] = true;
                }
            }
        }
        
        vector<int> result;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            result.push_back(it->val);
        }
        return result;
    }
};
