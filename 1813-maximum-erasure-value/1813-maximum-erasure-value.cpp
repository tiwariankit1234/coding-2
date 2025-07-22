#define ll long long
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        ll n=nums.size();
       ll sum=0,l=0,r=0,maxscore=INT_MIN;
        
        unordered_map<ll,ll>mp;
        while(r<n){
            sum+=nums[r];
            mp[nums[r]]++;
            if(mp[nums[r]]>1){   // shrink condition when frequency of one element is greater than equal t0 1;
                sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                mp.erase(nums[l]);
                l++;
            }
            maxscore=max(maxscore,sum);
            r++;
        }
        return maxscore;
    }
};