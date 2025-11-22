
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return NULL;
        if(!head->next)return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};