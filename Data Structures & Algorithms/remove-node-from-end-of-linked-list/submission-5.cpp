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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nodes = 0;
        ListNode *temp = head;
        while(temp != nullptr){
            nodes += 1;
            temp = temp->next;
        }
        int remnode = nodes - n;
        // cout << remnode;
        ListNode *prev = nullptr, *curr = head, *nextNode = head -> next;
        if(head->next == nullptr){
            head = nullptr;
            return head;
        }
        if(remnode == 0){
            head = head -> next;
            return head;
        }
        while(remnode > 0){
            prev = curr;
            curr = nextNode;
            nextNode = nextNode -> next;
            remnode -= 1;
        }
        // cout << prev -> val << " " << curr -> val << " " << nextNode -> val << endl;
        prev -> next = nextNode;
        curr-> next = nullptr;
        return head;
    }
};
