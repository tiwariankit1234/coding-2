#define ll long long 
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll m=grid.size();
        ll n=grid[0].size();
        vector<ll>prefix(n,0);
        prefix[0]=grid[0][0];
        for(ll i=1;i<n;i++){
            prefix[i]=grid[0][i]+prefix[i-1];
        }
         vector<ll>suffix(n,0);
         suffix[n-1]=grid[1][n-1];
         for(ll j=n-2;j>=0;j--){
            suffix[j]=suffix[j+1]+grid[1][j];
         }
         ll ans=LONG_LONG_MAX;
        //  for(auto it:prefix)
        //  cout<<it<<" ";
        //  cout<<endl;

        //  for(auto it:suffix)
        //  cout<<it<<" ";
        //  cout<<endl;
         for(ll i=0;i<n;i++){
          ll upper=prefix[n-1]-prefix[i];
          ll lower=suffix[0]-suffix[i];
           ll minians=max(upper,lower);
           ans=min(ans,minians);
         }
         return ans;
    }
};