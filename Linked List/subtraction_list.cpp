#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    static Node* head;
    static bool borrow;

    static Node* subLinkedList(Node* l1, Node* l2) {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;

        l1 = removeZeros(l1);
        l2 = removeZeros(l2);

        int len1 = getLength(l1);
        int len2 = getLength(l2);
        if (len1 == 0) return l2;
        if (len2 == 0) return l1;

        Node *lNode = nullptr, *sNode = nullptr;
        Node *temp1 = l1, *temp2 = l2;

        if (len1 != len2) {
            lNode = len1 > len2 ? l1 : l2;
            sNode = len1 > len2 ? l2 : l1;
            sNode = paddZeros(sNode, abs(len1 - len2));
        } else {
            while (l1 != nullptr && l2 != nullptr) {
                if (l1->data != l2->data) {
                    lNode = l1->data > l2->data ? temp1 : temp2;
                    sNode = l1->data > l2->data ? temp2 : temp1;
                    break;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
        }

        borrow = false;
        Node* ans = subtractLinkedListHelper(lNode, sNode);
        ans = removeZeros(ans);
        if (ans == nullptr) return new Node(0);
        return ans;
    }

    static Node* removeZeros(Node* head) {
        Node* curr = head;
        while (curr != nullptr && curr->data == 0) {
            curr = curr->next;
        }
        return curr;
    }

    static int getLength(Node* node) {
        int size = 0;
        while (node != nullptr) {
            node = node->next;
            size++;
        }
        return size;
    }

    static Node* paddZeros(Node* sNode, int diff) {
        if (sNode == nullptr) return nullptr;

        Node* zHead = new Node(0);
        diff--;
        Node* temp = zHead;
        while (diff-- != 0) {
            temp->next = new Node(0);
            temp = temp->next;
        }
        temp->next = sNode;
        return zHead;
    }

    static Node* subtractLinkedListHelper(Node* l1, Node* l2) {
        if (l1 == nullptr && l2 == nullptr && borrow == false)
            return nullptr;

        Node* previous = subtractLinkedListHelper(
            (l1 != nullptr) ? l1->next : nullptr,
            (l2 != nullptr) ? l2->next : nullptr
        );

        int d1 = l1->data;
        int d2 = l2->data;
        int sub = 0;

        if (borrow) {
            d1--;
            borrow = false;
        }

        if (d1 < d2) {
            borrow = true;
            d1 += 10;
        }

        sub = d1 - d2;

        Node* current = new Node(sub);
        current->next = previous;

        return current;
    }
};

Node* Solution::head = nullptr;
bool Solution::borrow = false;

int main() {
    // You can add test cases here to check the functionality.
    return 0;
}
