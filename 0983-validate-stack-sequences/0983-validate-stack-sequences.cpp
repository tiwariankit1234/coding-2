class Solution {
public:
    bool validateStackSequences(vector<int>& push, vector<int>& pop) {
        int n=push.size();
        int j=0;
        stack<int>st;
        for(int i=0;i<n;i++){
           
            st.push(push[i]);
            while(!st.empty() and st.top()==pop[j] and j<n){
             
                st.pop();
                j++;
               
            }
          
        }

        return j==n;


    }
};