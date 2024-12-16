class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;
        int i=0,j=0;
        while(j<n){
            if(dq.empty() ||  dq.front()+1==nums[j]){
                dq.push_front(nums[j]);
            }
            else{
                dq.clear();
                dq.push_front(nums[j]);
            }
            if(j-i+1==k){
                if(dq.size()==k){
                    ans.push_back(dq.front());

                }
                else{
                   ans.push_back(-1); 
                }
                dq.pop_back();
            }
            i++;
            j++;
        }
        return ans;
    }
};