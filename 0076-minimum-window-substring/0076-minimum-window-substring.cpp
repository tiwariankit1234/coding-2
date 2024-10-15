class Solution {
public:
    string minWindow(string s, string t) {
        int n=t.size();
        int m=s.size();
        int i=0,j=0,len=INT_MAX,charcount=0,start=-1;

        // count frequency

        unordered_map<int,int>mp;
        for(auto it:t){
        mp[it]++;
        charcount++;
        }

        while(j<m){
            if(mp[s[j]]>0){
              charcount--;
            }
            mp[s[j]]--;
            while(charcount==0){
          if((j-i+1)<len){
            len=j-i+1;
            start=i;
          }
          mp[s[i]]++;
          if(mp[s[i]]>0){
            charcount++;
          }
          
          i++;
              
            }
          j++;  
        }
        if(start==-1)return "";
        string z=s.substr(start,len);
        return z;
    }
};