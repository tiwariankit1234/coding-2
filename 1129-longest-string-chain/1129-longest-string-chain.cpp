class Solution {
public:
bool possible(string &s,string &t){
    int m=s.size(),n=t.size();
    int i=0,j=0;
    bool flag=false;
    if(s.size()!=t.size()+1)return false;
    while(i<m){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else if(!flag and s[i]!=t[j]){
            flag=true;
           i++;
        }
        else{
            return false;
        }
    }
    return true;
}
    int longestStrChain(vector<string>& words) {
        int n=words.size(),ans=1;
        sort(words.begin(),words.end(),[](string &a,string &b){
            return (a.size()<b.size());
        });
         for(auto it:words){
            cout<<it<<" ";
        }
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(possible(words[i],words[j])){
                    cout<<i<<" "<<j<<" "<<words[i]<<" "<<words[j]<<endl;
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        ans=max(ans,dp[i]);
                    }
                }
            }
        }
        // for(auto it:dp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        return ans;
    }
};