class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode dummy(0); 
        ListNode* ptr = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                ptr->next = list1;    
                list1 = list1->next; 
            } else {
                ptr->next = list2;    
                list2 = list2->next; 
            }
            ptr = ptr->next; 
        }

        if (list1 != nullptr) {
            ptr->next = list1;
        } else {
            ptr->next = list2;
        }
        return dummy.next;
    }
};