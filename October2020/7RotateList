/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findKth(ListNode* head, int k){
        int c=0;
        ListNode* temp=head, *tmp=head;
        while(temp && c<k){
            c++;
            temp=temp->next;
        }
        while(temp){
            temp=temp->next;
            tmp=tmp->next;
        }
        return tmp;        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *kth=NULL, *temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        if(n==0)
            return head;
        k=k%n;
        if(k==0 )
            return head;
        
        temp=head;
        kth = findKth(head, k);
        head = kth;
        ListNode* tmp = head;
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next=temp;
        while(tmp->next!=head){
            tmp=tmp->next;
        }
        tmp->next=NULL;
        return head;
    }
};
