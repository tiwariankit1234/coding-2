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
  ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            ListNode* nxt = cur->next;  // store next
            cur->next = prev;           // reverse link
            prev = cur;                 // move prev
            cur = nxt;                  // move cur
        }
        return prev; // new head
    }

    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // cout<<slow->val<<endl;
        ListNode* x=slow->next;
         slow->next=NULL;
        // cout<<x->val<<endl;
        ListNode* l2=reverseList(x);
        // cout<<l2->val<<endl;
        ListNode* l1=head;
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;
        while(l1 and l2){
            ListNode* t1=l1->next;
            ListNode* t2=l2->next;
            temp->next=l1;
            temp=l1;
            temp->next=l2;
            temp=l2;
            l1=t1;
            l2=t2;
        }
        if(l1)temp->next=l1;
      ;
    }
};