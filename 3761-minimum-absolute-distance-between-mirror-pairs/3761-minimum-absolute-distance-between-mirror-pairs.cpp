class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
         map<int,deque<int>>mp;
         for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
         }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int num=nums[i];
            string s=to_string(num);
            reverse(s.begin(),s.end());
            int req=stoi(s);
            if(mp.find(req)!=mp.end()){
                auto& it=mp[req];
                int idx1=upper_bound(it.begin(),it.end(),i)-it.begin();
                if(idx1!=it.size()){
                    ans=min(ans,it[idx1]-i);
                }
                auto temp=lower_bound(it.begin(),it.end(),i);
                temp--;
                int idx2=temp-it.begin();
                if(idx2>=0){
                    ans=min(ans,i-it[idx2]);
                }
            }
            mp[nums[i]].pop_front();
           
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};