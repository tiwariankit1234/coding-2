class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(isalpha(s[i])){
                st.push(s[i]);
            }
            else{
                string newstring="";
                while(!st.empty() and st.top()!='('){
                    newstring+=st.top();
                    st.pop();
                }
                st.pop();
                
                int n=newstring.size();
                for(int i=0;i<n;i++)
                st.push(newstring[i]);

                newstring="";
            }
        }

        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};