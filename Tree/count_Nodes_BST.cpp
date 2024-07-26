// class Solution{
// public:
//     void Helper(Node *root, int l, int h, int &cnt)
//     {
//         if(root == nullptr)return;
//         if(root->data >= l && root->data <= h)cnt++;
//         if(root->data > l)
//         Helper(root->left, l, h, cnt);
//         if(root->data < h)
//         Helper(root->right, l, h, cnt);
//     }
//     int getCount(Node *root, int l, int h)
//     {
//       // your code goes here   
//       int cnt = 0;
//       Helper(root, l, h, cnt);
//       return cnt;
//     }
// };