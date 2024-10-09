//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// minimum add to make parenthesis valid
//s="())" ans=1
class Solution {
public:
    int minAddToMakeValid(string s) {
       int n=s.size();
       stack<char>st;
       int count=0;

       for(int i=0;i<n;i++){
        if(!st.empty() and st.top()=='(' and s[i]==')'){
        st.pop();
       }
       else if(s[i]=='('){
        st.push(s[i]);
       }
       else{
        count++;
       }
      
    }
      return count+st.size();
    }
};