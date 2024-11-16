class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1 and k==1)return {nums[0]};
        deque<int>dq;
        int i=0,j=0;
        vector<int>ans;
       dq.push_back(nums[0]);

        while(j<n){
         if(nums[j]!=(dq.back()+1))dq.clear();
      

         dq.push_back(nums[j]);

            if(j-i+1==k){
                if(dq.size()==k){
                    ans.push_back(dq.back());
                    dq.pop_front();
                }
                else{
                    ans.push_back(-1);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};