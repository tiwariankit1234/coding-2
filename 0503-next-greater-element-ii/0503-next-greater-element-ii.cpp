class Solution {
public:
// void f(stack<int>st){
//     while(st.size()){
//        cout<<st.top()<<" ";
//        st.pop();
//     }
//     return ;
// }
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextgreater;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            nextgreater.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)nextgreater.push_back(nums[i]);
        stack<int>st;
        for(int i=nextgreater.size()-1;i>=(n);i--){
           while(!st.empty() and nextgreater[i]>=st.top()){
            st.pop();
           }
            st.push(nextgreater[i]);
        }
        // f(st);
        for(int i=n-1;i>=0;i--){
            int num=nums[i];
            
             while(!st.empty() and num>=st.top()){
            st.pop();
           }
            if(!st.empty() and num<st.top()){
               ans[i]=st.top();
            }
            else{
                ans[i]=-1;
            }
             
           st.push(nums[i]);
        }
        return ans;
    }
};