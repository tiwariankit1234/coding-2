#define ll long long
class Solution {
public:
ll dp[(int)1e5+2];
vector<ll>precompute;
unordered_map<ll,ll>mp;
ll f(int curridx,vector<int>&power){
    ll n=power.size();
    if(curridx>=n)return 0;
    if(dp[curridx]!=-1)return dp[curridx];
    ll taken=(ll)power[curridx]*mp[power[curridx]];
    taken=taken+f(precompute[curridx],power);
    ll notaken=f(curridx+1,power);
 
    return dp[curridx]=max(taken,notaken);
}
    long long maximumTotalDamage(vector<int>& power) {
        precompute.resize(power.size(),power.size());
        sort(power.begin(),power.end());
        for(auto it:power)mp[it]++;
        power.clear();
        for(auto it:mp){
            power.push_back(it.first);
        }
        sort(power.begin(),power.end());
         memset(dp,-1,sizeof(dp));
        for(ll i=0;i<power.size();i++){
            ll num=power[i];
            auto it1=upper_bound(power.begin()+i+1,power.end(),num-1);
            
            if(it1!=power.end() and *it1!=power[i]+1 and *it1!=power[i]+2){
                // cout<<i<<" "<<power[i]<<" "<<*it1<<endl;
                ll idx1=it1-power.begin();
                // cout<<idx1<<endl;
                precompute[i]=min(precompute[i],idx1);
            }
            
            auto it2=upper_bound(power.begin()+i+1,power.end(),num+2);
            // cout<<i<<" "<<power[i]<<" "<<*it2<<endl;
            if(it2!=power.end()){
                // cout<<i<<" "<<power[i]<<" "<<*it2<<endl;
                ll idx2=it2-power.begin();
                // cout<<idx2<<endl;
                precompute[i]=min(precompute[i],idx2);
            }
        }
        // for(auto it:precompute){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return f(0,power);
    }
};