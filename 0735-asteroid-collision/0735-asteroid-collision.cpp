class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        st.push(nums[0]);
        vector<int>ans;
        for(int i=1;i<n;i++){
             cout<<nums[i]<<endl;
            if(st.size() and nums[i]<0 and st.top()>0){
                while(st.size() and nums[i]<0 and st.top()>0 and abs(nums[i])-abs(st.top())>0){
                        st.pop();
                }
                if(st.size() and abs(nums[i])==abs(st.top()) and nums[i]<0 and st.top()>0){
                    st.pop();
                }
               else if(st.size() and nums[i]<0 and st.top()>0 and abs(nums[i])-abs(st.top())<0){
                    continue;
                }
                else{
                    st.push(nums[i]);
                }

            }
            else{
                st.push(nums[i]);
            }
        }
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};