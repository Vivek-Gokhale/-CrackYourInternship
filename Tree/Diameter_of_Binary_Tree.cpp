
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

    int Helper(TreeNode *root, int &maxi)
    {
        if(root == nullptr)
        return 0;
        int leftDepth = Helper(root->left, maxi);
        int rightDepth = Helper(root->right, maxi);
        maxi = max(maxi, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        Helper(root, maxi);
        return maxi;
    }
};