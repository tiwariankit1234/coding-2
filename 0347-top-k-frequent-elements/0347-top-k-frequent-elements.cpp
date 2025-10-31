#define pii pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pii>pq;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k>0){
            auto [freq,num]=pq.top();
            pq.pop();
            freq--;
            ans.push_back(num);
            k--;
        }
        return ans;
    }
};