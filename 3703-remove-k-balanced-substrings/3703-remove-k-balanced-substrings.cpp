class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, int>> st;
        string t = "";
        int count1 = 0, count2 = 0,n=s.size();
        for (int i = 0; i < n; i++) {
            // for(int j=0;j<st.size();j++){
            // cout<<i<<" "<<st[j].first<<" "<<st[j].second<<" ";
            // }
            // cout<<endl;
            if (st.empty()) {
                st.push_back({s[i], 1});
            } else if (st.back().first != s[i]) {
                st.push_back({s[i], 1});
                if (k == 1) {
                    if (st.size() - 2 >= 0 and s[i] == ')' and
                        st[st.size() - 2].first == '(' and
                        st[st.size() - 2].second >= k) {
                        for (int j = 0; j < 2; j++) {
                            st.pop_back();
                        }
                    }
                }
            } else if (st.back().first == s[i]) {
                st.push_back({s[i], st.back().second + 1});
                
                if (st.back().second == k) {
                    int x=st.size();
                    if ((x - 1 - k) >= 0 and s[i] == ')' and
                        st[x - 1 - k].first == '(' and
                        st[x - 1 - k].second >= k) {
                        for (int j = 0; j < (k + k); j++) {
                            st.pop_back();
                        }
                    }
                }
            }
        }
        for (auto it : st) {
            t.push_back(it.first);
        }
        return t;
    }
};