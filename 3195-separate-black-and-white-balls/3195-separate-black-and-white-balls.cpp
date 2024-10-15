class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        vector<int>v(n,0);
        long long count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                count++;
            }
            v[i]=count;
        }
      long long ans=0;
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
              ans+=v[i];
            }
        }
        return ans;
    }
};