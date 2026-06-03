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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            ListNode* curr = head;
            ListNode* prev = nullptr;
            ListNode* itr = lists[i];
            while (curr != nullptr && itr != nullptr) {
                if (curr->val > itr->val) {
                    ListNode* temp = itr;
                    itr = itr->next;
                    temp->next = curr;
                    if (prev == nullptr)
                        head = temp;
                    else
                        prev->next = temp;
                    prev = temp;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
            if (itr != nullptr) {
                if (prev == nullptr) {
                    head = itr;
                } else {
                    prev->next = itr;
                }
            }
        }
        return head;
    }
};
