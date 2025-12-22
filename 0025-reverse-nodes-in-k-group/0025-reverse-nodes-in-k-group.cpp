
class Solution {
public:
    void reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return;
    }
    ListNode *f(ListNode* curr,int k){
        k=k-1;
         while(k>0 and curr){
            curr=curr->next;
            k--;
         }
         return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
            return NULL;
        if (!head->next)
            return head;
         ListNode* temp=head;
         ListNode* prev=NULL;
         while(temp){
            ListNode* kthnode=f(temp,k);
            if(kthnode==NULL){
                if(prev){
                    prev->next=temp;
                }
                break;
            }
            ListNode* next=kthnode->next;
            kthnode->next=NULL;
             reverse(temp);
             if(temp==head){
                head=kthnode;
             }
            
            if(prev){
                prev->next=kthnode;
            }
            prev=temp;
            temp=next;
         }
         return head;
    }
};