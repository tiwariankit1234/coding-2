class Solution {
public:
    string robotWithString(string s) {
        string t = "";
        int n = s.size();
        stack<char> st;

        // Precompute min char from i to end
        vector<char> minchar(n);
        minchar[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minchar[i] = min(s[i], minchar[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            st.push(s[i]);

            // Pop from stack if top <= min remaining char
            while (!st.empty() && (i == n - 1 || st.top() <= minchar[i + 1])) {
                t.push_back(st.top());
                st.pop();
            }
        }

        return t;
    }
};
