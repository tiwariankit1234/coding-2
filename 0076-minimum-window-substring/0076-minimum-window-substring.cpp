class Solution {
public:
bool check(unordered_map<char,int>&mp1,unordered_map<char,int>&mp2){
    if((int)mp1.size()<(int)mp2.size())return false;
    for(auto it:mp2){
        char ch=it.first;
        int freq=it.second;
        if(mp1[ch]-mp2[ch]<0 )return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        unordered_map<char,int>mp2,mp1;
        int charactercnt=0;
        for(auto it:t){
            mp2[it]++;
            charactercnt++;
        }
         int lefty=-1,righty=-1,n=s.size(),ans=INT_MAX,l=0,r=0,formed=0;
        while(r<n){
            mp1[s[r]]++;
            if(mp2.find(s[r])!=mp2.end() and mp1[s[r]]<=mp2[s[r]]){
                formed++;
            }
            while(l<=r and formed==charactercnt){
                if((r-l+1)<ans){
                    lefty=l;
                    righty=r;
                }
                ans=min(ans,r-l+1);
                if(mp2.find(s[l])!=mp2.end() and mp1[s[l]]<=mp2[s[l]])formed--;
                mp1[s[l]]--;
                if(mp1[s[l]]==0)mp1.erase(s[l]);
                l++;
            }
            r++;
         }
         if(lefty==-1 and righty==-1)return "";
          return s.substr(lefty,righty-lefty+1);

    }
};