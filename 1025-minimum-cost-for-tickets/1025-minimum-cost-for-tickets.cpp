class Solution {
public:
int dp[366];
int f(int idx,vector<int>& cost,vector<int>& day){
    int n=day.size();
    if(idx==n){
        return 0;
    }
    if(dp[idx]!=-1)return dp[idx];
    int cost1=cost[0]+(f(idx+1,cost,day));
    int cost2;
    cost2=cost[1];
    int index=upper_bound(day.begin(),day.end(),day[idx]+6)-day.begin();
  
    
        cost2+=f(index,cost,day);
    
      index=upper_bound(day.begin(),day.end(),day[idx]+29)-day.begin();
      int cost3=cost[2];
      
    
        cost3+=f(index,cost,day);
      
           return dp[idx]=min({cost1,cost2,cost3});
}

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return f(0,costs,days);
    }
};