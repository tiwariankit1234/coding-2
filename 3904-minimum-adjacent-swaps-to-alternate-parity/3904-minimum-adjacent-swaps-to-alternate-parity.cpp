#define rep(i,n) for(int i=0;i<n;i++)
#define v vector<int>
class Solution {
public:
int helper(vector<int>temp){
   // agar odd hain toh odd ko even indices me pochana hain
      int n=temp.size(),count=0;
      for(int i=0;i<n;i++){
        count+=abs(temp[i]-2*i);
      }
      return count;
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
       v even,odd;
       rep(i,n){
        if(nums[i]&1){
            odd.push_back(i);
        }
        else{
            even.push_back(i);
        }
       }

       if(abs((int)odd.size()-(int)even.size())>1)return -1;
        
        int ans=INT_MAX;
       if(even.size()>=odd.size()) ans=min(ans,helper(even));
        if(odd.size()>=even.size()) ans=min(ans,helper(odd));
        return ans;

        
    }
};