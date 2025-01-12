class Solution {
public:
    bool canConstruct(string s, int k) {
        int oddfreq=0;
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto it:mp){
            if(it.second&1)
            oddfreq++;
        }
        int n=s.size();
        if(k>=oddfreq and k<=n)return true;
        return false;
    }
};