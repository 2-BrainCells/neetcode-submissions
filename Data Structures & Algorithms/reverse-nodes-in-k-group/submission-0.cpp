class Solution {
   public:
    ListNode* revLL(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* temp = head;
        ListNode* newLL = nullptr; 
        int size_ll = 0;

        while (temp != nullptr) {
            size_ll += 1;
            temp = temp->next;
        }

        int reps = size_ll / k;
        int dup_k = k;

        ListNode* prevTail = nullptr;

        for (int i = 0; i < reps; i++) {
            ListNode* front = head;
            ListNode* back = head;

            while (dup_k > 1) {
                back = back->next;
                dup_k -= 1;
            }

            head = back->next;
            dup_k = k;
            back->next = nullptr;
            temp = revLL(front);

            if (newLL == nullptr) {
                newLL = temp;  
            } else {
                prevTail->next = temp; 
            }

            prevTail = front;
        }

        if (prevTail != nullptr) {
            prevTail->next = head;
        }
        return newLL == nullptr ? head : newLL;
    }
};