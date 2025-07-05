class Solution {
public:
#define ll long long
int dp[1005][1005];
    int f(int idx, ll k, string& s, ll length) {
        
        // cout<<idx<<" "<<k<<" "<<length<<endl;
        if(idx<0)return 0;
        if(dp[idx][length]!=-1){
            return dp[idx][length];
        }
        if (s[idx] == '0') {

            return dp[idx][length]=1+f(idx - 1, k, s,length + 1);
        } else {
            if(length<31){
                ll newk=k-(1LL<<length);
            if (newk >= 0) {
        return dp[idx][length]=max(1+f(idx-1,newk,s,length+1),f(idx-1,k,s,length));
            }
      }
            
            return dp[idx][length]=f(idx-1,k,s,length);
        }
      return 0;
    }
        int longestSubsequence(string s, int k) {
            int n = s.size();
            memset(dp,-1,sizeof(dp));
            return f(n - 1, k, s, 0);
        }
    };