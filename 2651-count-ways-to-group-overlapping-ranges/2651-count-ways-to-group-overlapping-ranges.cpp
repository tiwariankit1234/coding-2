#define ll long long 
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
       ll n=ranges.size();
       if(n==1)return 2;
        sort(ranges.begin(),ranges.end());
        ll count=1;
        ll prev=ranges[0][1];
        for(ll i=1;i<n;i++){
            if(ranges[i][0]<=prev){
                prev=max((ll)ranges[i][1],prev);
                
            }
            else{
                count++;
                prev=ranges[i][1];
            }
        }
        int mod=1e9+7;
           long long result = 1;
        for (int i = 0; i < count; i++) {
            result = (result * 2) % mod;
        }
        return result;
    }
};