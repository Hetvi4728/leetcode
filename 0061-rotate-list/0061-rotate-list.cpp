class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        int n = 0;
        ListNode* temp = head;

        while(temp != nullptr) {
            n++;
            temp = temp->next;
        }

        k = k % n;

        for(int i = 0; i < k; i++) {
            ListNode* temp = head;

            while(temp->next->next != nullptr) {
                temp = temp->next;
            }

            ListNode* last = temp->next;
            temp->next = nullptr;
            last->next = head;
            head = last;
        }

        return head;
    }
};