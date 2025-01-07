class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.size();
        vector<int>prefix(n,0),suffix(n,0);
        prefix[0]=0,suffix[n-1]=0;
        int countoneend=0,countonestart=0,prefixindices=0,suffixindices=0;
        for(int i=0;i<n;i++){
             prefix[i]=countonestart*i-prefixindices;
             if(s[i]=='1')
             {
                countonestart++;
                prefixindices+=i;
             }
        }
        for(int i=n-1;i>=0;i--){
         suffix[i]=suffixindices-countoneend*i;
         if(s[i]=='1'){
            countoneend++;
            suffixindices+=i;
         }
         }
         vector<int>ans(n,0);
         for(int i=0;i<n;i++){
            ans[i]=prefix[i]+suffix[i];
         }
         return ans;
        }
    
};