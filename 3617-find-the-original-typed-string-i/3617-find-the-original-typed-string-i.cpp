class Solution {
public:
    int possibleStringCount(string s) {
        int n=s.size();
        int count=1;
        int l=0,r=1;
        while(r<n){
            if(s[l]!=s[r]){
                l=r;
                r++;
            }
            else if(s[l]==s[r]){
                count++;
                r++;
            }
        }
        return count;
    }
};