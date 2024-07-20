
  
#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_map<ListNode*, int> mp;
        // ListNode *curr = headA;
        // while(curr != nullptr)
        // {
        //     mp[curr] = 1;
        //     curr = curr->next;
        // }
        // curr = headB;
        // while(curr != nullptr)
        // {
        //     if(mp.find(curr) != mp.end())
        //     return curr;
        //     curr = curr->next;
        // }
        // return nullptr;
        ListNode *intersect = nullptr;
        ListNode *curr = headA;
        while(curr != nullptr)
        {
            curr->val = -1 * curr->val;
            curr = curr->next;
        }
        curr = headB;
        while(curr != nullptr)
        {
            if(curr->val < 0)
            {
                curr->val = abs(curr->val);
                intersect = curr;
                break;
            }
            
            curr = curr->next;
        }
        curr = headA;
        while(curr != nullptr)
        {
            curr->val = abs(curr->val);
            curr = curr->next;
        }
        return intersect;
    }
};