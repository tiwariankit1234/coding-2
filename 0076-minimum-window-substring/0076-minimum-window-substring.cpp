class Solution {
public:
    string minWindow(string s, string t) {
        map<int,int>mp;
        int n=s.size();
        for(char c:t){
            mp[c]++;
        }
        int k=0;
        for(auto it:mp)
        k+=it.second;

        int stidx=-1;
      
        int charcnt=0,l=0,r=0,length=INT_MAX;
        while(r<n){
           mp[s[r]]--;
           if(mp[s[r]]>=0){
            charcnt++;
           }
           while(charcnt==k){
             mp[s[l]]++;
             if(mp[s[l]]>0){
                charcnt--;
                if((r-l+1)<length){
                    length=r-l+1;
                    stidx=l;
                }
             }
             l++;
           }
           r++;
        }
        if(stidx==-1)return "";
        return s.substr(stidx,length);
    }
};