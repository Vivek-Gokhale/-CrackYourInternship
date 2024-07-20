
   struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// 121. Middle of linked list

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};