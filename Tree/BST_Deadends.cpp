#include <bits/stdc++.h>
using namespace std;
struct Node {
int data;
Node * right, * left;
};

/*You are required to complete below method */
class Solution{
  public:
    bool Helper(Node *root, int lb, int rb)
    {
        if(root == nullptr)return false;
        if(root->left == nullptr && root->right == nullptr)
        {
            if((root->data-lb == 1) && (rb-root->data == 1))return true;
            return false;
        }
        return (Helper(root->left, lb, root->data) || Helper(root->right, root->data, rb));
    }
    bool isDeadEnd(Node *root)
    {
        //Your code hereret
        return Helper(root, 0, 100);
        
    }
};