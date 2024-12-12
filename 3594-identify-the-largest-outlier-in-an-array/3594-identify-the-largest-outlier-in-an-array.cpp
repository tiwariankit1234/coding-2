class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        // for(auto it:nums){
        //    
        // }
         totalsum=accumulate(nums.begin(),nums.end(),0);
        cout<<totalsum<<endl;

        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans=INT_MIN;
        for(auto it:nums){
            mp[it]--;
            if( ((totalsum-it)%2==0) and mp.find(((totalsum-it)/2))!=mp.end() and mp[(totalsum-it)/2]>0){
              ans=max(ans,it);
            }
            mp[it]++;
        }

       return ans;
    }
};