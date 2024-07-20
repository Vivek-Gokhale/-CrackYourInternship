
//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p=head;
        ListNode* q=nullptr;
        int cnt=1;

        while(cnt!=left){ //move to left
            q=p;
            p=p->next;
            cnt++;
        }

        ListNode* curr=p->next; 
        ListNode* prev=p;
        cnt++; //move pointers by one...

        while(cnt<=right){ //reverse till right..
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            cnt++;
        }

        if(q!=nullptr) q->next=prev; //adjust pointers after reverse..
        else head=prev; 

        if(p!=nullptr) p->next=curr;

        return head;
    }
};