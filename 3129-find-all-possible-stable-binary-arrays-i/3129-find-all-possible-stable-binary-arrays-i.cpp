class Solution {
public:
int mod=1e9+7;
vector<vector<vector<vector<int>>>>dp;
int f(int zero,int one,int previousbit,int rep,int limit){
    // cout<<zero<<" "<<one<<" "<<previousbit<<" "<<rep<<" "<<limit<<endl;
    if(rep==(limit+1))return 0;
    if(zero<0 || one<0)return 0;
    if(zero==0 and one==0){
        return 1;
    }
    if(dp[zero][one][previousbit][rep]!=-1)return dp[zero][one][previousbit][rep];
    int count=0;
    
         if(previousbit==0){
            count=(count+f(zero-1,one,0,rep+1,limit))%mod;
            count=(count+f(zero,one-1,1,1,limit))%mod;
          }
           if(previousbit==1){
            count=(count+f(zero-1,one,0,1,limit))%mod;
            count=(count+f(zero,one-1,1,rep+1,limit))%mod;
           }
           return dp[zero][one][previousbit][rep]=count;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        int count=0;
         dp = vector<vector<vector<vector<int>>>>(
            zero + 1, vector<vector<vector<int>>>(
                one + 1, vector<vector<int>>(
                    2, vector<int>(limit + 1, -1)
                )
            )
        );
         count=(count+f(zero-1,one,0,1,limit))%mod;
        
         count=(count+f(zero,one-1,1,1,limit))%mod;
         return count;
    }
};