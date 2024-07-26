#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    void Helper(int i, Node *root, vector<vector<Node *>> &order)
    {
        if(root == nullptr)return;
        if(i < order.size())
        {
            root->next = nullptr;
            order[i].back()->next = root;
            order[i].push_back(root);
        }
        else
        {
            root->next = nullptr;
            order.push_back({root});
        }
        Helper(i+1, root->left, order);
        Helper(i+1, root->right, order);
    }
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == nullptr)return root;
        q.push(root);
        while(!q.empty())
        {
            int siz = q.size();
            while(siz--)
            {
                auto it = q.front();
                q.pop();
                if(siz == 0)
                {
                    it->next = nullptr;
                    //continue;
                }
                else
                {
                     it->next = q.front();
                }
               
                if(it->left)
                q.push(it->left);
                if(it->right)
                q.push(it->right);
            }
        }
        return root;
        
        // vector<vector<Node*>> order;

        // Helper(0, root, order);
        // return root;

    }
};