
 
 //sort ll of 0 1 2 elements
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int zeroCnt = 0;
        int oneCnt = 0;
        int twoCnt = 0;
        Node *curr = head;
        while(curr != nullptr)
        {
            if(curr->data == 0)
            {
                zeroCnt++;
            }else if(curr->data == 1)
            {
                oneCnt++;
            }
            else
            {
                twoCnt++;
            }
            curr = curr->next;
        }
        curr = head;
        while(curr != nullptr)
        {
            if(zeroCnt > 0)
            {
                curr->data = 0;
                zeroCnt--;
            }
            else if(oneCnt > 0)
            {
                curr->data = 1;
                oneCnt--;
            }
            else if(twoCnt > 0)
            {
                curr->data = 2;
                twoCnt--;
            }
            else
            {
                
            }
            curr = curr->next;
        }
        return head;
        
        
    }
};
