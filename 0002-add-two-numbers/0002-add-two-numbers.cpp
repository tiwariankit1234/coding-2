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
int checklength(ListNode *temp){
    int length=0;
    while(temp){
        length++;
        temp=temp->next;
    }
    return length;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x=checklength(l1),y=checklength(l2);
        if(x>=y){
        ListNode* temp=l1;
        int carry=0;
        while(temp->next){
            temp->val=temp->val+((l2)?l2->val:0)+carry;
             int x=temp->val;
             temp->val=x%10;
             carry=x/10;
             temp=temp->next;
             if(l2)l2=l2->next;
        }
        cout<<carry<<" "<<temp->val<<endl;
        temp->val=temp->val+((l2)?l2->val:0)+carry;
        int x=temp->val;
         carry=x/10;
         if(carry){
            temp->val=x%10;
            temp->next=new ListNode(x/10);
            temp=temp->next;
         }
        
        return l1;
        }
        else{
             ListNode* temp=l2;
        int carry=0;
        while(temp->next){
            temp->val=temp->val+((l1)?l1->val:0)+carry;
             int x=temp->val;
             temp->val=x%10;
             carry=x/10;
             temp=temp->next;
             if(l1)l1=l1->next;
        }
        temp->val=temp->val+((l1)?l1->val:0)+carry;
          int x=temp->val;
         carry=x/10;
         if(carry){
            temp->val=x%10;
            temp->next=new ListNode(x/10);
            temp=temp->next;
         }
        return l2;
        }
        return NULL;
    }
};