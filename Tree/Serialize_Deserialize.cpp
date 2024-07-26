#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        if(root == nullptr) return data;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr) {
                data.append("#,");
            } else {
                data.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        stringstream str(data);
        string value;
        getline(str, value, ',');
        TreeNode *root = new TreeNode(stoi(value));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(getline(str, value, ',')) {
                if(value == "#") {
                    node->left = nullptr;
                } else {
                    TreeNode *leftNode = new TreeNode(stoi(value));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }
            if(getline(str, value, ',')) {
                if(value == "#") {
                    node->right = nullptr;
                } else {
                    TreeNode *rightNode = new TreeNode(stoi(value));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
