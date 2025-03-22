class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int>small(n,0);
        small[0]=nums[0];
        for(int i=1;i<n;i++)
        small[i]=min(nums[i],small[i-1]);

        stack<int>st;
        int index=-1;
        for(int i=n-1;i>=0;i--){
            if(small[i]!=nums[i]){
                index=i;
              st.push(nums[i]);
              break;
            }
        }
       for(int i=index-1;i>=0;i--){
         if(nums[i]==small[i])continue;
         while(!st.empty() and st.top()<=small[i]){
            st.pop();
         }
         if(!st.empty() and nums[i]>st.top()and nums[i]!=small[i])
        return true;
        else
        st.push(nums[i]);
       }
            return false;
    }
};