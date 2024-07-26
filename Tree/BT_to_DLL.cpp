struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
 

// This function should return head to the DLL
class Solution {
public:
    // Function to convert binary tree to doubly linked list and return it.
    Node *sentinel, *temp;
    
    void Helper(Node *root) {
        if (root == nullptr)
            return;
        
        Helper(root->left);
        
        // Link the previous node (temp) with the current node (root)
        temp->right = root;
        root->left = temp;
        
        // Move the temp pointer to the current node
        temp = root;
        
        Helper(root->right);
    }
    
    Node * bToDLL(Node *root) {
        if (root == nullptr) 
            return nullptr;
        
        // Create a sentinel node to help with list creation
        sentinel = new Node(-1);
        temp = sentinel;
        
        // Perform the in-order traversal and linking
        Helper(root);
        
        // The first real node is the right child of the sentinel
        Node *ans = sentinel->right;
        
        // Set the left pointer of the first node to nullptr
        if (ans != nullptr)
            ans->left = nullptr;
        
        // Clean up the sentinel node
        delete sentinel;
        
        return ans;
    }
};

