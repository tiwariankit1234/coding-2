class Solution {
public:
// edge cases ki isme mp.size()<=2 bhi chalegi kyounki ek basket me ek hi type ka fruits rahega 
//
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,maxsize=0,k=2;
        unordered_map<int,int>mp;

        while(r<n){
            mp[nums[r]]++;
            if(mp.size()>2){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            if(mp.size()<=2)maxsize=max(maxsize,(r-l+1));
            r++;
        }
        return maxsize;
    }
};