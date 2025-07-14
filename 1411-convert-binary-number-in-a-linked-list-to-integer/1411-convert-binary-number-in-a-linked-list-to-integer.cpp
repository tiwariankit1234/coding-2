
class Solution {
public:
int ans=0;
int f(ListNode* head){
    if(head==NULL)return -1;
   int size=f(head->next);
   if(head->val==1){
    ans+=pow(2,size+1);
   }
   return size+1;

}
    int getDecimalValue(ListNode* head) {
       f(head);
       return ans;
    }
};