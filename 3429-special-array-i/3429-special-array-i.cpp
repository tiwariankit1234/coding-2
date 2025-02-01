class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        // even and odd 
       
        for(int i=1;i<n;i++){
            if(nums[i]&1 and !(nums[i-1]&1)){
              continue;
            }
            else if(!(nums[i]&1) and (nums[i-1]&1)){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};