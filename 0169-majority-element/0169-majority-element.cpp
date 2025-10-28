class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0,major=-1;
        for(int i=0;i<n;i++){
            if(count==0){
               major=nums[i];
                count++;
            }
            else if(nums[i]==major)count++;
            else{
                count--;
                if(count==0){major=nums[i];
                count=1;
            }
        }
        }
        // check it is the major one ;
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==major)count++;
        }
        if(count>(n/2))return major;
        return -1;
    }
};