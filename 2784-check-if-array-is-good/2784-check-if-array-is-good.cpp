class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxelement=INT_MIN;
        for(auto it:nums){
            mp[it]++;
            maxelement=max(it,maxelement);
        }
        if(n==(maxelement+1) and mp[maxelement]==2){
            for(int i=1;i<maxelement;i++){
                if(mp.find(i)==mp.end())return false;
            }
            return true;
        }
        return false;
    }
};