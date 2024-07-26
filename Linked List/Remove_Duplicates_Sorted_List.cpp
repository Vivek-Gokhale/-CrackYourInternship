

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
          if (head == nullptr || head -> next == nullptr) return head;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while(curr != nullptr && curr->next != nullptr)
    {
        if(curr->val == curr->next->val)
        {
            while(curr != nullptr && curr->next != nullptr && curr->val == curr->next->val)
            {
                curr = curr->next;
            }
            if(prev != nullptr)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                head = curr->next;
                curr = curr->next;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }    
    return head;
    }
};