class Solution {
public:
int dp[1002][1002];
int f(int i,int j,string& s1,string& s2){
    int n1=s1.size(),n2=s2.size();
    if(i==n1){
        int cost=0;
        for(int k=j;k<n2;k++){
            cost+=s2[k];
        }
        return cost;
    }
    if(j==n2){
        int cost=0;
        for(int k=i;k<n1;k++){
            cost+=s1[k];
        }
        return cost;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int cost1=INT_MAX,cost2=INT_MAX,cost3=INT_MAX;
    if(s1[i]==s2[j]){
        cost1=f(i+1,j+1,s1,s2);
    }
    else{
        cost2=s1[i]+f(i+1,j,s1,s2);
        cost3=s2[j]+f(i,j+1,s1,s2);
    }
    return dp[i][j]=min({cost1,cost2,cost3});
}
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
           memset(dp,-1,sizeof(dp));
        return f(0,0,s1,s2);
    }
};