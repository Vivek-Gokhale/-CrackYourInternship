

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
//O(N ^ 2) sol 
    // int findHgt(TreeNode *root)
    // {
    //     if(root == nullptr)return 0;
    //     int d1 = findHgt(root->left);
    //     int d2 = findHgt(root->right);
    //     return max(d1, d2)+1;
    // }
    // bool Helper(TreeNode *root)
    // {
    //     if(root == nullptr)return true;
    //     int left = findHgt(root);
    //     int right = findHgt(root);
    //     if(abs(left-right) > 1)return false;
    //     bool r1 = Helper(root->left);
    //     bool r2 = Helper(root->right);
    //     if(!r1 || !r2) return false;
    //     return true;
    // }
    int Helper(TreeNode *root)
    {
        if(root == nullptr)return 0;
        int left = Helper(root->left);
        int right = Helper(root->right);
        if(left == -1 || right == -1)return -1;
        if(abs(left-right) > 1)return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(Helper(root) == -1)return false;
       return true;
    }
};