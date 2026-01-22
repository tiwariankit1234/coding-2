class Solution {
public:
bool check(vector<int>nums){
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1])return false;
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        if(check(nums))return 0;
        int count=0;
        while(!check(nums)){
           
            unordered_map<int,int>mp;
            for(int i=0;i<(nums.size()-1);i++){
                int sum=nums[i]+nums[i+1];
                if(mp.find(sum)==mp.end()){
                 mp[sum]=i;
                }
            }
            count++;
            int minsum=INT_MAX;
            for(auto it:mp){
              minsum=min(minsum,it.first);
            }
            vector<int>temp;
            int idx=mp[minsum];
            for(int i=0;i<=idx-1;i++){
                temp.push_back(nums[i]);
            }
            temp.push_back(minsum);
            for(int i=idx+2;i<nums.size();i++){
                temp.push_back(nums[i]);
            }
            //  cout<<count<<endl;
            // for(auto it:temp){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            if(check(temp))return count;
            nums=temp;
           
        }
        return 0;
    }
};