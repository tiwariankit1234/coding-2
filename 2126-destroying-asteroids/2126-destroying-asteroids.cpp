class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(),nums.end());
       long long remainingmass=mass;
        int index=0;
        while(index<nums.size()){
          if(nums[index]<=remainingmass){
          remainingmass+=nums[index];
          }
          else{
            return false;
          }
          index++;
        }
        if(remainingmass<0)return false;
        return true;
    }
};