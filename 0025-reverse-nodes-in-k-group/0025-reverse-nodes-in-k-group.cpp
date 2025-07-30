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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>arr;
         
        ListNode* temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int i=0,n=arr.size();
        if(arr.size()==1)return head;
     
        while(i<n){
            if(i+(k)<=n){
            reverse(arr.begin()+i,arr.begin()+i+(k));
            }
            i+=k;
        }
        for(auto it:arr){
            cout<<it<<" ";
        }
        cout<<endl;
        i=2;

        ListNode* newhead=new ListNode(arr[0]);
           ListNode* prev=newhead;
        ListNode* current=new ListNode(arr[1]);
       
       prev->next=current;
       prev=current;
        while(i<n){
         current=new ListNode(arr[i]);
         if(prev){
            prev->next=current;
         }
         prev=current;
         
         i++;
        }
        return newhead;
    }
};