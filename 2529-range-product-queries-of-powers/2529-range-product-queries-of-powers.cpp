#define ll long long
class Solution {
public:
int mod=1e9+7;
long long modpow(long long a, long long b, int mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
long long modInverse(long long a, int mod) {
    return modpow(a, mod - 2, mod);
}


    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll>powertwo;
        int x=log2(n),k=queries.size();
        for(int i=0;i<32;i++){
        
            if(n&(1<<i)){
                // cout<<(1<<i)<<endl;
                powertwo.push_back(1<<i);
            }
        }
        //  for(auto it:)

       int p=powertwo.size();
       for(int i=1;i<p;i++){
        powertwo[i]=((powertwo[i])*(powertwo[i-1]))%mod;
       }
      
       cout<<endl;
    // for(auto it:powertwo){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
        vector<int>ans;
        for(int i=0;i<k;i++){
            int a=queries[i][0],b=queries[i][1];
            int left=a-1<0 ?1:powertwo[a-1];
            int right=powertwo[b];
           long long x = (right * modInverse(left, mod)) % mod;
            // if(x<0){
            //     x*=-1;
            // }
           
            ans.push_back(x);
        }
       
        return ans;
    }
};