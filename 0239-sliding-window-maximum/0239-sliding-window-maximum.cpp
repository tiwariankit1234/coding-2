class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // ek window ka nikal lunga
       vector<int>ans;
       int n=nums.size();
       priority_queue<pair<int,int>>pq;
       for(int i=0;i<k;i++){
       pq.push({nums[i],i});
       }
      ans.push_back(pq.top().first);
       int t=1;
       int i=1,j=k;
       while(j<n){
         pq.push({nums[j],j});
         int element=pq.top().first;
         int index=pq.top().second;
         while(pq.size()>0 and (index<i)){
            pq.pop();
            index=pq.top().second;
         }
         if(pq.size()>0)ans.push_back(pq.top().first);
         j++;
         i++;
       }
       return ans;
    }
};