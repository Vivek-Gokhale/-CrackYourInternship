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
    // void checkSum(TreeNode *root, long long k, int &pathCnt)
    // {
    //     if(root == nullptr) return;
    //     if(root->val == k)
    //     {
    //         pathCnt++;
    //     }
    //     checkSum(root->left, k - root->val, pathCnt);
    //     checkSum(root->right, k - root->val, pathCnt);
    // }
    
    // void Helper(TreeNode *root, int k, int &pathCnt)
    // {
    //     if(root == nullptr) return;
    //     checkSum(root, k, pathCnt);
    //     Helper(root->left, k, pathCnt);
    //     Helper(root->right, k, pathCnt);
    // }
    void Helper(TreeNode* root, long long targetSum, int &pathCnt, long long sum, unordered_map<long long, int> mp)
    {
        if(root == nullptr)return;
        sum += root->val;
        if(sum == targetSum)
        pathCnt++;
        if(mp.find(sum-targetSum) != mp.end())
        {
            pathCnt += mp[sum-targetSum];
        }
        mp[sum]++;
        Helper(root->left, targetSum, pathCnt, sum, mp);
        Helper(root->right, targetSum, pathCnt, sum, mp);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
       int pathCnt = 0;
       unordered_map<long long, int> mp;
       Helper(root, targetSum, pathCnt, 0, mp);
       return pathCnt; 
    }
};
