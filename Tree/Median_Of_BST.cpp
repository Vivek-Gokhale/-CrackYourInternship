
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void Helper(struct Node *root, vector<int> &inorder)
{
    if(root == nullptr)return;
    Helper(root->left, inorder);
    inorder.push_back(root->data);
    Helper(root->right, inorder);
    
}
float findMedian(struct Node *root)
{
      //Code here
      vector<int> inorder;
      Helper(root, inorder);
      int n = inorder.size();
      if(n % 2 == 0)
      {
          return (inorder[n/2] + inorder[(n/2)-1]) / 2.0;
      }
      return inorder[n/2] / 1.0;
}
