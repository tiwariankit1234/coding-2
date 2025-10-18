
class Solution {
public:
      set<int>st;
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        for(auto it : nums)mp[it]++;
        if(k == 0)return mp.size();
        vector<vector<int>>intr;
       int ans =0;
        
        sort(nums.begin(), nums.end());
        int f = nums[0]-k;
        for(auto it : nums){
            int str = it-k, end = it + k;
            f = max(str, f);
            
            if( f<=end and st.count(f)==0){
               st.insert(f);
                f++;ans++;
            }
            
        }

return ans;
    }
};