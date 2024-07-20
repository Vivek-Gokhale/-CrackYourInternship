struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

};

class solution {
public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long n1 = 0;
        long long n2 = 0;
        int mod = 1e9+7;
        
        Node *num1 = first;
        Node *num2 = second;
        
        // Traverse the first linked list to form the first number
        while (num1 != nullptr) {
            n1 = (n1 * 10 + num1->data) % mod;
            num1 = num1->next;
        }
        
        // Traverse the second linked list to form the second number
        while (num2 != nullptr) {
            n2 = (n2 * 10 + num2->data) % mod;
            num2 = num2->next;
        }
        
        // Multiply the two numbers and return the result modulo 10^9+7
        return (n1 * n2) % mod;
    }
};