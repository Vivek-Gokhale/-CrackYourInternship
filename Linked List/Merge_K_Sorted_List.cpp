#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode(-1);
        ListNode *sentinel = dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                sentinel->next = left;
                left = left->next;
            } else {
                sentinel->next = right;
                right = right->next;
            }
            sentinel = sentinel->next;
        }

        if (left != nullptr) {
            sentinel->next = left;
        } else if (right != nullptr) {
            sentinel->next = right;
        }

        ListNode* mergedList = dummy->next;
        delete dummy;  // Clean up the dummy node
        return mergedList;
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int low, int high) {
        if (low == high) {
            return lists[low];
        }
        int mid = low + (high - low) / 2;
        ListNode *left = mergeSort(lists, low, mid);
        ListNode *right = mergeSort(lists, mid + 1, high);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeSort(lists, 0, lists.size() - 1);
    }
};
