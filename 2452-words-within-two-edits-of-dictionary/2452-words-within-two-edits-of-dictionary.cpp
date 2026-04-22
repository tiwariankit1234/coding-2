class Solution {
public:
    // bool possible(string s,int changes,unordered_set<string>&st){
    //     if(changes>2)return false;
    //     if(st.find(s)!=st.end())return true;

    //     int n=s.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<26;j++){
    //             string newstring=s;
    //             newstring[i]='a'+j;
    //             if(newstring[i]!=s[i]){
    //                 if(possible(newstring,changes+1,st))
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool check(string& s, string& t) {
        int i = 0, j = 0, n = s.size(), changes = 0;
        while (i < n) {
            if (s[i++] != t[j++])
                changes++;
        }
        if (changes > 2)
            return false;
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {

        unordered_set<string> st;
           vector<string>ans;
        for (string s : queries) {
            bool flag = false;
            for (string t : dictionary) {
                if (check(s, t)) {
                    flag = true;
                    ans.push_back(s);
                    break;
                }
            }
        }
      
        return ans;
    }
};