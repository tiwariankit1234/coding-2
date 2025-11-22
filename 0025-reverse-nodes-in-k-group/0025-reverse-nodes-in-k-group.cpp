
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
        ListNode *prevlast=NULL;
         ListNode* temp=head;
        while(temp){
        ListNode *kthnode=f(temp,k);
        if(kthnode==NULL){
            if(prevlast){
                prevlast->next=temp;
            }
            break;
        }
        ListNode *nextnode=kthnode->next;
        kthnode->next=NULL;
        reverse(temp);
        if(temp==head){
            head=kthnode;
        }
        else{
            prevlast->next=kthnode;
        }
        prevlast=temp;
        temp=nextnode;
        }
        return head;
    }
};