  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
      if (!head || !head->next || !head->next->next)
            return;
        
        // Find the middle of the linked list
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // Reverse the second half of the linked list
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr;
        while (curr != nullptr) 
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Merge the two halves of the linked list
        ListNode *first = head;
        ListNode *second = prev;
        while (second) {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
   


    }
};