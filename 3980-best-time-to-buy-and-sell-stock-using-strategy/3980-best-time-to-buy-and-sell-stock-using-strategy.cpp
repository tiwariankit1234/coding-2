#define ll long long 
class Solution {
public:
    long long maxProfit(vector<int>& nums, vector<int>& strategy, int k) {
        ll n=nums.size();
        vector<ll>prefixsum(n,0);
        prefixsum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=nums[i]+prefixsum[i-1];
        }
        
       ll profit=LLONG_MIN,cost=0;
        for(int i=0;i<n;i++){
            cost+=nums[i]*strategy[i];
        }
        profit=max(profit,cost);
        // cout<<cost<<endl;
        ll l=0,r=0,sum=0,temp=0;
    
        while(r<n){
            sum+=nums[r]*strategy[r];
            // cout<<sum<<endl;
            if(r-l+1==k){
                temp=cost-sum+prefixsum[r]-prefixsum[l+k/2-1];
                profit=max(profit,temp);
                sum=sum-nums[l]*strategy[l];
                l++;
            }
            r++;
        }
        return profit;
    }
};