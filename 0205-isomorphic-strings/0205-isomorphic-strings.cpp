class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,char>mp;
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end() and st.find(t[i])==st.end()){
                mp[s[i]]=t[i];
                st.insert(t[i]);

            }
            else if(mp.find(s[i])==mp.end() and st.find(t[i])!=st.end()){
             return false;
            }
           else if(mp.find(s[i])!=mp.end()){
               auto ch=mp[s[i]];
               if(ch!=t[i])return false;
           }
        }
        return true;
    }
};