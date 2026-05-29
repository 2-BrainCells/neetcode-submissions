/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* revLL(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        while (curr != nullptr) {
            ListNode *nextNode = curr->next; 
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        int n = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            n += 1;
            temp = temp->next;
        }

        int jumps = (n - 1) / 2; 
        temp = head;
        while (jumps > 0) {
            temp = temp->next;
            jumps -= 1;
        }

        ListNode* head2 = temp->next; 
        temp->next = nullptr;        
        head2 = revLL(head2);
        ListNode* h1 = head;
        ListNode* h2 = head2;
        
        while (h2 != nullptr) {
            ListNode* next1 = h1->next;
            ListNode* next2 = h2->next;

            h1->next = h2;
            h2->next = next1;

            h1 = next1;
            h2 = next2;
        }
    }
};