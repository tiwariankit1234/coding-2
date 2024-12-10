class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string currentstring="";
            for(int j=i;j<n;j++){
                 
                currentstring+=s[j];
                if(j>i and s[j]!=s[j-1])
                  break;
                  
                  mp[currentstring]++;
            }
        }
          int len=-1;
        for(auto it:mp){
            if(it.second>=3){
               len=max(len,(int)((it.first).size()));
            }
        }
        return len;

    }
};