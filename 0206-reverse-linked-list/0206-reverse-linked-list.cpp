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
  ListNode* f(ListNode* head){
     if(!head)return NULL;
    if(!head->next)return head;
   
    
     ListNode* nxtnode=f(head->next);
    head->next->next=head;
    head->next=NULL;
     return nxtnode;
  }
    ListNode* reverseList(ListNode* head) {
       if(!head || !head->next)return head;
        return f(head);
    }
};