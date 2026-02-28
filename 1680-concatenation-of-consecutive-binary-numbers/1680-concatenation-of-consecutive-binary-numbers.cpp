#define ll long long
class Solution {
public:
ll mod=1e9+7;
int f(int i){
    string k="";
    while(i>0){
        if(i%2)k.push_back('1');
        else k.push_back('0');
        i=i/2;
    }
    reverse(k.begin(),k.end());
    return k.size();
}
    int concatenatedBinary(int n) {
        ll ans=0;
        string s="";
        
        ans=1;
        for(int i=2;i<=n;i++){
            int k=f(i);
            ans = ((ans * ((1 << k) % mod)) % mod + i) % mod;
        }
        return ans;
    }
};