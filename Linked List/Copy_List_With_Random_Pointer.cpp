
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    void copyList(Node *head)
    {
        Node *curr = head;
        while(curr != nullptr)
        {
            Node *copy = new Node(curr->val);
            Node *next = curr->next;
            curr->next = copy;
            copy->next = next;
            curr = next;
        }
    }
   void handleRandPointer(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        if (curr->random != nullptr) // Check if random pointer is not null
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
}

    Node* detachList(Node* head)
    {
        Node *sentinal = new Node(-1);
        Node *temp = sentinal;
        Node *curr = head;
        while(curr != nullptr)
        {
            temp->next = curr->next;
            temp = temp->next;
            curr->next = temp->next;
            curr = curr->next;
        }
        return sentinal->next;
    }

    Node* copyRandomList(Node* head) {
    // unordered_map<Node*, Node*> umap;
    // Node *curr = head;
    // while(curr != nullptr)
    // {
    //     Node *copyNode = new Node(curr->val);
    //     umap[curr] = copyNode;
    //     curr = curr->next;
    // }
    // curr = head;
    // while(curr != nullptr)
    // {
    //     umap[curr]->next = umap[curr->next];
    //     umap[curr]->random = umap[curr->random]; 
    //     curr = curr->next;
    // }
    // return umap[head];
    if(head == nullptr)return nullptr;
    copyList(head);
    handleRandPointer(head);
    return detachList(head);

    
    }
};