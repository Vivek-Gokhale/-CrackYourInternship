
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:

    ListNode* Helper(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *revHead = Helper(head->next);
        head->next->next = head;
        head->next = nullptr;
        return revHead;

    }
    ListNode* reverseList(ListNode* head) {
    // ListNode *prev = nullptr;
    // ListNode *curr = head;

    // while(curr != nullptr)
    // {
    //    ListNode *next = curr->next;
    //    curr->next = prev;
    //    prev = curr;
    //    curr = next;
    // }    
    // return prev;

    return Helper(head);
    
    }
};