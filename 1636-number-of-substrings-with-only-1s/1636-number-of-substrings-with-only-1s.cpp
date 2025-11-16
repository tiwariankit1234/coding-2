class Solution {
public:
      int mod=1e9+7;
    int numSub(string s) {
        int count=0,l=0,r=0;
        int n=s.size();
        while(r<n){
            if(s[r]=='0'){
                r++;
                l=r;
            }
            else{
                count=(count%mod+(r-l+1)%mod)%mod;
                r++;
            }
        }
        return count;
    }
};