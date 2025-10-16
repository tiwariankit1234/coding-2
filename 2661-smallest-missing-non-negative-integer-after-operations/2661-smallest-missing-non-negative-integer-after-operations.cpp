class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            // cout<<nums[i]<<" "<<value<<" "<<nums[i]%value<<endl;
            mp[((nums[i])%value+value)%value]++;
        }

        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<endl;
         
        unordered_map<int,int>newmap;
        for(auto it:mp){
            auto [val,freq]=it;
            for(int i=1;i<=freq;i++){
                newmap[val+value*(i-1)]++;
            }
        }
        // for(auto it:newmap){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(int i=0;i<=1e5;i++){
            if(newmap.find(i)==newmap.end())return i;
        }

        return -1;
    }
};