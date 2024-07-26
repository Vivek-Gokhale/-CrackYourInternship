struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = nullptr;
    }
};

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *beforeOdd = new Node(-1);
        Node *temp1 = beforeOdd;
        Node *afterOdd = new Node(-1);
        Node *temp2 = afterOdd;
        Node *curr = head;
        while(curr != nullptr)
        {
            if(curr->data % 2 == 0)
            {
                temp1->next = curr;
                temp1 = temp1->next;
            }
            else
            {
                temp2->next = curr;
                temp2 = temp2->next;
            }
            curr = curr->next;
        }
        temp2->next = nullptr;
        temp1->next = afterOdd->next;
        head = beforeOdd->next;
        return head;
    }
};
