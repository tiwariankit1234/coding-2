class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.size();
        string t = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (st.empty()) {
                    st.push(s[i]);
                } else {
                    t.push_back(s[i]);
                    st.push(s[i]);
                }
            } else {
                st.pop();
                if (!st.empty()) {
                    t.push_back(s[i]);
                }
            }
        }
        return t;
    }
};