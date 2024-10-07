class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        stack<char>st;
        st.push(s[0]);

        char ch;

        for(int i=1;i<n;i++){
            if(!st.empty())
            ch=st.top();
            else{
                ch=' ';
            }

            if((ch=='A' and s[i]=='B') || (ch=='C' and s[i]=='D')){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            cout<<st.size()<<" "<<i<<endl;
        }
        return st.size();
    }
};