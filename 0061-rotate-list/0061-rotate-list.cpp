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
    
    int count=0;
    while(head){
        count+=1;
        head=head->next;
    }
    return count;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !(head->next)||k==0)return head;
        int length=f(head);
        k=k%length;
        if(k==0)return head;
        int actualstep=length-k-1;
        ListNode* temp=head;
        while(actualstep){
            temp=temp->next;
            actualstep--;
        }
        cout<<temp->val<<endl;
        ListNode* end=head;
        while(end->next){
            end=end->next;
        }
        ListNode* start=temp->next;
        temp->next=NULL;
        end->next=head;
        return start;
    }
};