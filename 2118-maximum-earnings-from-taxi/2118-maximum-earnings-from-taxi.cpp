#define ll long long
class Solution {
public:
vector<ll> dp;
   ll f(vector<vector<int>>& rides,int idx, vector<int>&str){
        if(idx==rides.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        ll nonpick=f(rides,idx+1,str);
        ll start=rides[idx][0];
       ll end=rides[idx][1];
        ll tip=rides[idx][2];
        ll pick=0;
     		ll ind=lower_bound(str.begin()+idx+1,str.end(),end)-str.begin();
            pick=end-start+tip+f(rides,ind,str);
            // cout<<ind<<" "<<pick<<endl; 
        return dp[idx]=max(pick,nonpick);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
         dp.resize(rides.size(), -1);
        vector<int>str;
        for(int i=0;i<rides.size();i++)
            str.push_back(rides[i][0]);
        

        return f(rides,0,str);

    }
};