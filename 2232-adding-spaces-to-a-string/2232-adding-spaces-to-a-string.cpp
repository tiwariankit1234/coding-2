class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string t="";
        int n=s.size(),k=spaces.size();
        unordered_set<int>st(spaces.begin(),spaces.end());

        for(int i=0;i<n;i++){
            if(st.contains(i)){
                t.push_back(' ');
                t.push_back(s[i]);
            }
            else{
                t.push_back(s[i]);
            }
        }

        return t;

        
    }
};