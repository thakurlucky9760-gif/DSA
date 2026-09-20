/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 # define ed endl
 
 # define null NULL
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==null){
            return false;
        }
        if(head->next==null){
            return false;
        }
        
       ListNode* slow=head;
       ListNode* fast=head;

        while(fast != null && fast-> next !=null){
           slow= slow->next;
           fast= fast->next->next;

            if (slow==fast){
                return true;
            }

        }
        return false;
    }
};