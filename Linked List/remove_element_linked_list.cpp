

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    ListNode *sentinal = new ListNode(-1);
    sentinal->next = head;
    ListNode *prev = sentinal;
    ListNode *curr = head;
    while(curr != nullptr)
    {
        ListNode *toDelete = nullptr;
        if(curr->val == val)
        {
            prev->next = curr->next;
            toDelete = curr;
        }
        else
        {
            prev = curr;
        }
            curr = curr->next;
        
        if(toDelete != nullptr)
        {
            delete toDelete;
        }
    }
    ListNode *newHead = sentinal->next;
    delete sentinal;
    return newHead;

    }
};