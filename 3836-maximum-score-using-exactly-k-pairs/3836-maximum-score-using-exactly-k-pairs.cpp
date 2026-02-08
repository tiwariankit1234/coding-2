#define ll long long
class Solution {
public:
vector<int>nums3;
vector<int>nums4;
ll dp[102][102][102];
const ll INF = -1e18;


ll f(ll i,ll j,ll k){
    int n=nums3.size(),m=nums4.size();
    // cout<<i<<" "<<j<<" "<<k<<endl;
    if(k==0)return 0;
    if((i==n||j==m) and k>0)return -1e15; 
     if(dp[i][j][k]!=INF)return dp[i][j][k];
    ll ans=LLONG_MIN;
    ll taken=LLONG_MIN,notaken=LLONG_MIN;
    if(k>=1){
    taken=max((ll)nums3[i]*(ll)nums4[j]+f(i+1,j+1,k-1),taken);
    }
    notaken=max(notaken,f(i+1,j,k));
    notaken=max(notaken,f(i,j+1,k));
    //  cout<<i<<" "<<j<<" "<<k<<" "<<taken<<" "<<notaken<<endl;
    return dp[i][j][k]=max(taken,notaken);

}
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        nums3=nums1;
        nums4=nums2;
        // cout<<nums3.size()<<" "<<nums4.size()<<endl;
          fill(&dp[0][0][0], &dp[0][0][0] + 102*102*102, INF);
        return f(0,0,k);

    }
};