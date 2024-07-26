struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:

    ListNode* getMiddle(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
    ListNode* sentinel = new ListNode(-1);
    ListNode* dummy = sentinel;
    ListNode* left = list1;
    ListNode* right = list2;

    while (left != nullptr && right != nullptr) {
        if (left->val <= right->val) {
            dummy->next = left;
            dummy = dummy->next;
            left = left->next;
        } else {
            dummy->next = right;
            dummy = dummy->next;
            right = right->next;
        }
    }

    // Attach the remaining nodes of list1 or list2
    while (left != nullptr) {
        dummy->next = left;
        left = left->next;
        dummy = dummy->next;
    }
    while (right != nullptr) {
        dummy->next = right;
        dummy = dummy->next;
        right = right->next;
    }

    return sentinel->next;
}

    ListNode* sortList(ListNode* head) {
    if(head == nullptr || head->next == nullptr)return head;

    ListNode *mid = getMiddle(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = nullptr;
    left = sortList(left);
    right = sortList(right);
     ListNode* mergedLL = mergeList(left, right);
     return mergedLL;
        
    }
};