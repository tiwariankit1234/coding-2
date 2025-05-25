#define ll long long
ll mod=1e9+7; 
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<ll>freq(26,0);
        ll n=s.size();
        for(int i=0;i<n;i++)
            freq[s[i]-'a']++;

            while(t>0){
               vector<ll>newfreq(26,0);
                
                for(int i=2;i<26;i++){
                  if(freq[i-1]>=1){
                    newfreq[i]=freq[i-1];
                  }
                }
                newfreq[1]=(freq[0]%mod+freq[25]%mod)%mod;
                newfreq[0]=freq[25];
                 
               
               

            
                freq=newfreq;
             
                t--;
            }
            ll size=0;
          
          
            for(int i=0;i<26;i++){
              size=(size%mod+freq[i]%mod)%mod;
            }
            return size;
        
    }
};