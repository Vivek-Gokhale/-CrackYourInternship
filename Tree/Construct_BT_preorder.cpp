
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
    TreeNode* buildHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inordIdx)
    {
        if(preStart > preEnd || inStart > inEnd)return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inIdxRoot = inordIdx[preorder[preStart]];
        int leftTreeSize = inIdxRoot - inStart;

        root->left = buildHelper(preorder, preStart+1, preStart+leftTreeSize, inorder, inStart, inIdxRoot-1, inordIdx);
        root->right = buildHelper(preorder, preStart+1+leftTreeSize, preEnd, inorder, inIdxRoot+1, inEnd, inordIdx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inordIdx;
    for(int i=0; i<inorder.size(); i++)
    {
        inordIdx[inorder[i]] = i;
    }    
    TreeNode *root = buildHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inordIdx);
    return root;
    }
};