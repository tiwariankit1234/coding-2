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
        count++;
        head=head->next;
    }
    return count;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=f(head);
        ListNode* temp=head;
        for(int i=1;i<=(length-n-1);i++){
           temp=temp->next;
        }
        if((length-n-1)<0)return head->next;
        cout<<(length-n-1)<<endl;
        ListNode* remove=temp->next;
        ListNode* next=remove->next;
        temp->next=next;
        return head;
    }
};