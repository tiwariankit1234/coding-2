class Solution {
public:
    string removeDigit(string s, char digit) {
        int n=s.size();
        stack<char>st;
        st.push(s[0]);
        int k=1;
       for(int i=1;i<n;i++){
        if(!st.empty() and s[i]>st.top() and k>0 and st.top()==digit){
            st.pop();
            k--;
        }

        st.push(s[i]);
       }
       string t="";
       while(st.size()){
        if(st.top()==digit and k>0){
            st.pop();
            k--;
            continue;
        }
        t.push_back(st.top());
        st.pop();
       }
       reverse(t.begin(),t.end());
       return t;
    }
};