

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

 // 0 measn aleardy covered 
 // 1 means it has cemera
 // -1 means need to be covered
class Solution {
public:
int camera = 0;
    int Helper(TreeNode* root)
    {
        if(root == nullptr)return 0;
        int l = Helper(root->left);
        int r = Helper(root->right);
        if(l == -1 || r == -1)
        {
            camera++;
            return 1;
        }
        if(l == 1 || r == 1)
        {
            return 0;
        }
        return -1;

    }
    int minCameraCover(TreeNode* root) {
        if(Helper(root) == -1)return camera+1;
        return camera;
    }
};