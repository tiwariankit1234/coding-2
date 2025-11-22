
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
    int sizy(ListNode* curr){
        int size=0;
        while(curr){
           size+=1;
           curr=curr->next;
        }
        return size;
    }
    ListNode* f(ListNode* temp,int k){
        while(k>0 and temp){
            k--;
            temp=temp->next;
        }
        return temp;
    }


    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        if(!head->next)return head;
        int size=sizy(head);
       
        k=k%size;
         if(k==0)return head;

        ListNode* temp=head;
        ListNode* kthnode=NULL;
         kthnode=f(temp,size-(k+1));
         ListNode* newhead=kthnode->next;
         ListNode* nextnode=kthnode->next;
        while(temp->next){
            temp=temp->next;
        }
        kthnode->next=NULL;
        temp->next=head;
        return newhead;

    }
};