class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
    map<pair<char,int>,int>mp;
        for(int i=0;i<n;i++){
            char currentchar=s[i];
            int count=0;

            
            for(int j=i;j<n;j++){

                if(j>i and s[j]!=s[j-1]){
                  break;
                }
                  count++;
                 mp[{currentchar,count}]++;
            }
        }
          int len=-1;
        for(auto it:mp){
            if(it.second>=3){
               len=max(len,it.first.second);
            }
        }
        return len;

    }
};