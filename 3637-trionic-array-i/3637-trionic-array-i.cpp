class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size(),i=0;
        while(i<n){
            if((i+1)<n and nums[i]<nums[i+1]){
                while((i+1)<n and nums[i]<nums[i+1])i++;  // for increasing
                if((i+1)<n and nums[i]>nums[i+1]){         // for decreasing
                    while((i+1)<n and nums[i]>nums[i+1]){
                        i++;
                    }
                }
                  else return false;
                if((i+1)<n and nums[i]<nums[i+1]){
                     while((i+1)<n and nums[i]<nums[i+1])i++; 
                     if(i==n-1)return true;
                     else
                     return false;
                }
              
              
            }
            else return false;
        }
        return true;
    } 
};