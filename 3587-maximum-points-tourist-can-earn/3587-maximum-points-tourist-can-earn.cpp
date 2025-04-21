class Solution {
public:
int dp[201][201];
int f(int curr,int k,int day,vector<vector<int>>& stay,vector<vector<int>>& trav,int n){
   if(day>=k)return 0;
   if(dp[curr][day]!=-1)return dp[curr][day];

    // stay in the same city
   
    int stand=stay[day][curr]+f(curr,k,day+1,stay,trav,n);
    // travel to the other city
    int travel=0;
    for(int i=0;i<n;i++){
        if(i!=curr){
            int dest=i;
            travel=max(travel,trav[curr][dest]+f(dest,k,day+1,stay,trav,n));
        }
    }
    return dp[curr][day]=max(travel,stand);
}
    int maxScore(int n, int k, vector<vector<int>>& stay, vector<vector<int>>& trav) {    
   int maxpoint=0;
   memset(dp,-1,sizeof(dp));
 for(int i=0;i<n;i++){
    maxpoint=max(maxpoint,f(i,k,0,stay,trav,n));
 }
 return maxpoint;
    }
};