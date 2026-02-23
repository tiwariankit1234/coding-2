class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int reqsize=pow(2,k);
          unordered_set<string>st;
        int l=0,r=0,n=s.size();
        string t="";
        while(r<n){
            if(r-l+1==k){
                st.insert(s.substr(l,r-l+1));
                l++;
            }
            r++;
        }
        if((int)st.size()==reqsize)return true;
        return false;
    }
};