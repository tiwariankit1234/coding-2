class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        if(n==k)return "0";

        stack<char>st;
        st.push(s[0]);

        for(int i=1;i<n;i++){
            while(!st.empty() and s[i]<st.top() and k>0){
                st.pop();
                k--;
            }
            st.push(s[i]);     
        }

        while(k>0){
            if(!st.empty() and k>0){
            st.pop();
               k--;
            }
        }

           string t = "";
        while (!st.empty()) {
            t += st.top();
            st.pop();
        }
        reverse(t.begin(), t.end());

        // Removing leading zeros
        int start = 0;
        while (start < t.size() && t[start] == '0') {
            start++;
        }
        
        // Erase leading zeros
        t = t.substr(start);

        // If the result is empty after removing leading zeros, return "0"
        return t.empty() ? "0" : t;

    }
};