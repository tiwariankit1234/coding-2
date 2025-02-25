class Solution {
public:
    bool canPlaceFlowers(vector<int>&nums, int count) {

       int n=nums.size();
          if(count==0)return true;
          if(n==1){
            if(nums[0]==0)
            return true;
            else
            return false;
          }
          if(nums[0]==0 and nums[1]==0){
            count--;
            nums[0]=1;
          }
          if(nums[n-1]==0 and nums[n-2]==0){
            count--;
            nums[n-1]=1;
          }
       for(int i=1;i<(n-1);i++){
         if(nums[i]==0 and nums[i-1]==0 and nums[i+1]==0){
              nums[i]=1;
              count--;
         }
       }
       return count<=0;
    }
};