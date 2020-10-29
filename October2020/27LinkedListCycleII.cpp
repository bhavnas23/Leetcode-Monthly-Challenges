/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow)
                break;
        }
        if(!fast || !fast->next  || !slow)
            return NULL;
        int cycl = 1;
        slow=slow->next;
        while(slow!=fast){
            cycl++;
            slow=slow->next;            
        }
        
        slow=fast=head;
        for(int i=0; i<cycl; ++i){
            fast=fast->next;
        }
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};
