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
int f(ListNode* head){
    ListNode* temp=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}
    ListNode* rotateRight(ListNode* head, int k) {
      int size=f(head),count=0;
      if(k==0)return head;
      if(!head)return head;
      if(!(head->next))return head;
      if(size)
      k=k%size;
      if(k==0)return head;
    //   cout<<size<<endl;
      ListNode *temp=head;
      ListNode* prev=NULL;
      ListNode* curr=head;

      while(count<(size-k)){
        prev=curr;
         curr=curr->next;
        count++;
      }
     cout<<size-k<<" "<<count<<endl;
      
       if(prev)prev->next=NULL;
     ListNode *newhead=curr;
     prev=curr;
      while(curr and curr->next){
        curr=curr->next;
       prev->next=curr;
       prev=curr;
      }
     
    if(curr) curr->next=head;
     return newhead;
    }
};