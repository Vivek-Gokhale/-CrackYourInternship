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
    map<pair<int, int>, vector<TreeNode*>> mp;
    vector<TreeNode*> Helper(int low, int high)
    {

        if(low > high)return {nullptr};
        if(low == high)
        {
            TreeNode *root = new TreeNode(low);
            return mp[{low, high}] = {root};
        }
        if(mp.find({low, high}) != mp.end())
        return mp[{low, high}];
        vector<TreeNode*> result;
        for(int i=low; i<=high; i++)
        {
            vector<TreeNode*> leftBST = Helper(low, i-1);
            vector<TreeNode*> rightBST = Helper(i+1, high);
            
            for(TreeNode *leftR : leftBST)
            {
                for(TreeNode *rightR : rightBST)
                {
                    TreeNode *newNode = new TreeNode(i);
                    result.push_back(newNode);
                    newNode->left = leftR;
                    newNode->right = rightR;
                }
            }
        }
        return mp[{low, high}] = result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return Helper(1, n);
    }
};