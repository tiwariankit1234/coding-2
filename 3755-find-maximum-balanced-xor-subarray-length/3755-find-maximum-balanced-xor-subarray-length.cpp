class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
       map<pair<int,int>,int>mp;
       mp[{0,0}]=-1;
        int odd=0,newxor=0,maxlength=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                odd++;
            }
            newxor=newxor^nums[i];
            int even=(i+1)-odd;
            int x=even-odd;
              if(mp.find({x,newxor})!=mp.end()){
                maxlength=max(maxlength,i-mp[{x,newxor}]);
              }
              if(mp.find({x,newxor})==mp.end()){
                mp[{x,newxor}]=i;
              }  
        }
        return maxlength;
    }
};