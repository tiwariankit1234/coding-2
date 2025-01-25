#define ll long long 
class Solution {
public:
ll dp[1000005][2];
ll f(int total,vector<int>&cost,int idx){
    // cout<<total<<" "<<cost[idx]<<" "<<idx<<endl;
    if(total<0)return 0;
      if(total==0)return 0;
    if(idx==1){
        return (total)/cost[idx];
    }

        if(dp[total][idx]!=-1)return dp[total][idx];

  

      ll take=0;
    if(total-cost[idx]>=0){
     take=1+f(total-cost[idx],cost,idx);
    }
   ll notake=f(total,cost,idx+1);
    return dp[total][idx]=take+notake;
}
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        // ll count=0;
        // count+=total/cost2+1;
        // // cout<<count<<endl;
        // while(total>0){
        //    total-=cost1;
        //    if(total==0)
        //    count+=1;
        //    else if(total>0){
        //     count+=total/cost2+1;
        //    }
        // }

        // return count;
        // vector<vector<int>>dp(total+1,vector<int>(2,-1));
        vector<int>cost(2,0);
        memset(dp,-1,sizeof(dp));
        cost[0]=cost1;
        cost[1]=cost2;
        return 1+f(total,cost,0);
    }
};