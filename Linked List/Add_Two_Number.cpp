struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sentinal = new ListNode(-1);
        ListNode *temp = sentinal;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int digitOne = (l1 != nullptr) ? l1->val : 0;
            int digitTwo = (l2 != nullptr) ? l2->val : 0;
            int sum = digitOne + digitTwo + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *newNode = new ListNode(sum);
            temp->next = newNode;
            temp = temp->next;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
         ListNode *answer = sentinal->next;
    delete sentinal;
   
    return answer;
    }
};