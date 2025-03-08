class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n=s.size();
        int bc=0,wt=0,l=0,r=0,minchange=INT_MAX;
        while(r<n){
            if(s[r]=='W')wt++;
            else
            bc++;
            if(r-l+1==k){
                minchange=min(minchange,wt);
                if(s[l]=='W')wt--;
                else
                bc--;
                l++;
            }
            r++;
        }
        return minchange;
    }
};