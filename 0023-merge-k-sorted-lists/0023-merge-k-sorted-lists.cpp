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
struct cmp{
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        ListNode* dummy=new ListNode(-1);
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(auto it:lists){
            if(it)
            pq.push(it);
        }
        if(pq.size()==0)return NULL;
         ListNode* head=pq.top();
        dummy->next=head;
       
        pq.pop();
        if(head->next)pq.push(head->next);
        ListNode *temp=head;
        while(pq.size()){
            auto it=pq.top();
            temp->next=it;
            temp=it;
            pq.pop();
            if(it->next)
            pq.push(it->next);

        }
        return dummy->next;

    }
};