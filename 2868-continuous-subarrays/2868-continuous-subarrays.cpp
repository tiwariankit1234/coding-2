#define ll long long 

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ll n=nums.size();
        ll left=0,right=0;
        ll count=0;
        map<ll,ll>mp;
        while(right<n){
            mp[nums[right]]++;
           
            ll maxelement=mp.rbegin()->first;
            ll minelement=mp.begin()->first;
             ll difference=(abs)(maxelement- minelement);
             while(difference>2){
                mp[nums[left]]--;
                if(mp[nums[left]]==0)mp.erase(nums[left]);
                left++;
                if(mp.size()>0)maxelement=mp.rbegin()->first;
                if(mp.size()>0)minelement=mp.begin()->first;
                difference=(abs)(maxelement- minelement);
             }
             count+=right-left+1;
             right++;
        }
        return count;
    }
};