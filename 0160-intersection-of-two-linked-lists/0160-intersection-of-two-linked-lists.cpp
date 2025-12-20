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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1=0,length2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1->next){
            length1++;
            temp1=temp1->next;
        }
        while(temp2->next){
            length2++;
            temp2=temp2->next;
        }
        cout<<temp1->val<<" "<<temp2->val<<endl;
        if(temp1!=temp2)return NULL;
        
        length1++;
        length2++;
        temp1=headA;
        temp2=headB;
        if(length1<=length2){
            int x=length2-length1;
            for(int i=1;i<=x;i++){
                temp2=temp2->next;
            }
            while(temp1 and temp2){
                if(temp1==temp2)return temp1;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        else{
            int x=length1-length2;
            for(int i=1;i<=x;i++){
                temp1=temp1->next;
            }
            while(temp1 and temp2){
                if(temp1==temp2)return temp1;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return NULL;
        
    }
};