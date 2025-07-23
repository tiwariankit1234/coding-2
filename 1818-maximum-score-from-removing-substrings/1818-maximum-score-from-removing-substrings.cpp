#define rep(i,n) for (int i = 0; i < n; i++)
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();

        int count = 0;
        if (y >= x) {
            stack<char> st;
             // first loop for finding the count of ba 
            rep(i, n) {
                if (!st.empty() and s[i] == 'a' and st.top() == 'b') {
                    count += y;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
            string newstring = "";
            while (st.size()) {
                newstring.push_back(st.top());
                st.pop();
            }
            reverse(newstring.begin(),newstring.end());
            stack<char> newstack;
            int k = newstring.size();
            // for finding the count of ab 
            int i=0;
            rep(i,k) {
                if (!newstack.empty() and newstring[i] == 'b' and
                    newstack.top() == 'a') {
                    newstack.pop();
                    count += x;
                } else {
                    newstack.push(newstring[i]);
                }
            }
        } else {

            stack<char> st;
             // for find ing the count of ab
            rep(i, n) {
                if (!st.empty() and s[i] == 'b' and st.top() == 'a') {
                    count += x;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
            string newstring = "";
             while (st.size()) {
                newstring.push_back(st.top());
                st.pop();
            }
            reverse(newstring.begin(), newstring.end());
            stack<char> newstack;
            int k = newstring.size();
            // for finding the count of ba 
             int i=0;
            rep(i, k) {
                if (!newstack.empty() and newstring[i] == 'a' and
                    newstack.top() == 'b') {
                    newstack.pop();
                    count += y;
                } else {
                    newstack.push(newstring[i]);
                }
            }
        }
        return count;
           }
};