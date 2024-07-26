
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:

    ListNode* reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        
        while(head != nullptr)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
        
    }

    ListNode* findKthNode(ListNode *head, int k)
    {
        int cnt = 1;
        while(head != nullptr)
        {
            if(cnt == k)return head;
            head = head->next;
            cnt++;
        }
        return nullptr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *temp = head;
    ListNode *prevNode = nullptr;
    while(temp != nullptr)
    {
        ListNode *kthNode = findKthNode(temp, k);
        if(!kthNode)
        {
            if(prevNode)
            prevNode->next = temp;
            break;
        }
        ListNode *nextNode = kthNode->next;
        kthNode->next = nullptr;
        reverseList(temp);
        if(temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevNode->next = kthNode; 
        }
        prevNode = temp;
        temp = nextNode;

    } 
    return head;   
    }
};