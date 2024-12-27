class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<int,int>mp;
        int l=0,r=0;
        int maxsize=0;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            maxsize=max(maxsize,(r-l+1));
            r++;
        }
        return maxsize;
    }
};