class Solution {
   public:
    bool hasCycle(ListNode* head) {
        ListNode *slow, *fast;
        slow = head, fast = head;
        if(head == nullptr){
            return 0;
        }
        if(head->next == nullptr){
            return 0;
        }
        while(slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            if(fast->next->next == nullptr) return 0;
            else fast = fast->next->next;
            if(slow == fast){
                return 1;
            }
        }
        return 0;
    }
};
