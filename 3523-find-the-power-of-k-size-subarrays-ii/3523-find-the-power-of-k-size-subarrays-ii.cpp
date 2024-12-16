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
            if((j-i+1)==k){
                // cout<<"1"<<endl;
                if(dq.size()==k){
                    ans.push_back(dq.front());
                     dq.pop_back();

                }
                else{
                   ans.push_back(-1); 
                }
               
                i++;
            }
           cout<<dq.front()<<endl;
            // for(auto it:dq){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            
            j++;
        }
        return ans;
    }
};