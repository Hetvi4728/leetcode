class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0, head);

        ListNode* slow = temp;
        ListNode* fast = temp;

        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return temp->next;
    }
};