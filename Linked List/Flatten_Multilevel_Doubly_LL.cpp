// Definition for a Node.


#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node *curr = head;
        Node *tail = head;
        while(curr != nullptr)
        {
            if(curr->child)
            {
                if(curr->next)
                {

                    st.push(curr->next);
                    curr->next->prev = nullptr;

                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            tail = curr;
            curr = curr->next;
        }
        while(!st.empty())
        {
            Node *tp = st.top();
            st.pop();
            tail->next = tp;
            tp->prev = tail;
            while(tp != nullptr)
            {
                tail = tp;
                tp = tp->next;
            }
        }
        return head;
    }
};