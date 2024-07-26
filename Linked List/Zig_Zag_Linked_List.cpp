#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};


class Solution {
  public:
    Node* zigZag(Node* head) {
        // your code goes here
        Node *curr = head;
        Node *temp;
        int i=0;
        // i=0 for <
        // i=1 for >
        while(curr != nullptr && curr->next != nullptr)
        {
            if(i == 0)
            {
                if(curr->data > curr->next->data)
                {
                    swap(curr->data, curr->next->data);
                }
                i=1;
            }
            else
            {   
                if(curr->data < curr->next->data)
                {
                    swap(curr->data, curr->next->data);
                }
                i=0;
            }
            curr = curr->next;
        }
        return head;
    }
};