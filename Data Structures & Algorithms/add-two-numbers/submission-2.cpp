class Solution {
   public:
    int sizeLL(ListNode* head) { 
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr){
            count += 1;
            temp = temp -> next;
        }
        return count;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *ptr = nullptr, *temp;
        int carry = 0, value, sum;
        int size1 = sizeLL(l1), size2 = sizeLL(l2);
        int max_size = size1 > size2 ? size1 : size2;
        cout << max_size;
        while (max_size > 0) {
            cout << l1->val << " " << l2->val << " " << carry << endl;
            if (l2->next == nullptr) {
                temp = new ListNode(0);
                l2->next = temp;
            }
            if (l1->next == nullptr) {
                temp = new ListNode(0);
                l1->next = temp;
            }
            value = l1->val + l2->val + carry;

            if (value >= 10)
                carry = value / 10;
            else
                carry = 0;
            sum = value % 10;
            if (head == nullptr) {
                temp = new ListNode(sum);
                ptr = head = temp;
            } else {
                temp = new ListNode(sum);
                ptr->next = temp;
                ptr = ptr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
            max_size -= 1;
        }
        if (carry == 1) {
            temp = new ListNode(carry);
            ptr->next = temp;
            ptr = ptr->next;
        }
        return head;
    }
};