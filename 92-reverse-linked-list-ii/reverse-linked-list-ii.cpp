class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL) {
            return NULL;
        }

        if(left == right) {
            return head;
        }

        ListNode* before = NULL;
        ListNode* t = head;
        int pos = 1;

        // left position tak pahuchna
        while(pos < left) {
            before = t;
            t = t->next;
            pos++;
        }

        // reversal
        ListNode* curr = t;
        ListNode* prev = NULL;

        int time = right - left + 1;

        while(time--) {
            ListNode* nex = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        // Original left node is now the last node
        t->next = curr;

        // left se pehle wali node ko reversed list se connect
        if(before != NULL) {
            before->next = prev;
            return head;
        }

        // left == 1
        return prev;
    }
};