#define ll long long 
class Solution {
public:
vector<vector<ll>>ans;

void f(int idx,vector<int>&nums,ll target,vector<ll>&temp){
    ll n=nums.size();
        if(idx==n ){
            if(target==1){
            ans.push_back(temp);
        }
        return ;    
    }
    if(target%nums[idx]==0){
        temp.push_back(nums[idx]);
        ll newtarget=target/nums[idx];
        f(idx+1,nums,newtarget,temp);
        temp.pop_back();
    }
    f(idx+1,nums,target,temp);
    return ;
}

bool check(vector<ll>&nums1,vector<ll>&nums2){
    unordered_set<ll>s;
    for(auto it:nums1){
        s.insert(it);
    }
    for(auto it:nums2){
        if(s.find(it)!=s.end())
        return false;
    }
    return true;
}
        
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll n=nums.size();
        for(int i=0;i<n;i++){
            if((target%nums[i])!=0)
            return false;
        } 
        
        vector<ll>temp;
         f(0,nums,target,temp);
         ll k=ans.size();
         for(ll i=0;i<k;i++){
            for(ll j=i+1;j<k;j++){
                if(check(ans[i],ans[j])){
                    return true;
                }
            }
         }
         return false;
    }
};