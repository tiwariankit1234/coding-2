class Solution {
public:
int dp[1002];
int f(int idx,unordered_map<int,vector<int>>&mp){
    // cout<<"Ye function ke andhar wala"<<endl;
    // cout<<idx<<endl;
    if(dp[idx]!=-1)return dp[idx];
    auto temp=mp[idx];
    int ans=0;
    for(int j=0;j<temp.size();j++){
       ans=max(ans,1+f(temp[j],mp));
    }
    return dp[idx]=ans;
}
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<endl;
            for(int j=i-1;j>=max(i-d,0);j--){
               if(arr[j]>=arr[i])break;
               mp[i].push_back(j);
            }
            for(int j=i+1;j<=min(i+d,n-1);j++){
        
                    if(arr[j]>=arr[i])break;
                    mp[i].push_back(j);
                   
            }
        }
        // for(auto it:mp[0]){
        //     cout<<it<<endl;
        // }

        // cout<<"2"<<endl;
        int ans=0;
//  cout<<f(0,mp)<<endl;
//  cout<<"Ye bahar wala"<<endl;
        for(int i=0;i<n;i++){
            // cout<<"Ye answer"<<endl;
            // cout<<it.first<<" "<<f(it.first,mp)<<endl;
          ans=max(ans,f(i,mp));
        }
       
        return ans+1;
    }
};