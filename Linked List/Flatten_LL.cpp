#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = nullptr;
        bottom = nullptr;
    }

};


/*  Function which returns the  root of
    the flattened linked list. */
Node* flatten(Node* root) {
    if (!root) return nullptr;

    // Min-heap to store the nodes in sorted order
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;

    // Insert all nodes from the linked list and their bottom nodes into the heap
    Node* curr = root;
    while (curr) {
        pq.push({curr->data, curr});
        Node* bt = curr->bottom;
        while (bt) {
            pq.push({bt->data, bt});
            bt = bt->bottom;
        }
        curr = curr->next;
    }

    // Create a dummy node to serve as the start of the flattened list
    Node* sentinel = new Node(-1);
    Node* temp = sentinel;

    // Extract the nodes from the heap and form the new flattened list
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        temp->bottom = it.second;
        temp = temp->bottom;
    }

    // Return the flattened list starting from the first real node
    return sentinel->bottom;
}