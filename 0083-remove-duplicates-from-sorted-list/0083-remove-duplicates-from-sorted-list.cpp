
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* x = head;

        while (x != NULL && x->next != NULL) {
            if (x->val == x->next->val) {
                x->next = x->next->next;
            } else {
                x = x->next;
            }
        }

        return head;
    }
};
