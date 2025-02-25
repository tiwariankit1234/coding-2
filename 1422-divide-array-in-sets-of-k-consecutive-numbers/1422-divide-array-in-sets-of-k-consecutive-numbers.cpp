class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k)return false;
        sort(nums.begin(),nums.end());
    
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int group=0;
        for(int i=0;i<=(n-k);i++){
            int num=nums[i];
            bool flag=true;
            for(int j=num;j<(num+k);j++){
                if(mp.contains(j)){
                    mp[j]--;
                    if(mp[j]==0)mp.erase(j);
                }
                else{
                 flag=false;
                 break;
                }
            }
            if(flag)group++;
        }
       
        return group==(n/k);
    }
};