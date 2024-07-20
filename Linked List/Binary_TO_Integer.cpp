/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// 121. Binary Number to Integer Number
class Solution {
public:
    int getDecimalValue(ListNode* head) {
    int ans = 0;
    while(head != nullptr)
    {
        ans = ans << 1;
        ans += head->val;
        head = head->next;
    }
    return ans;    
    }
};