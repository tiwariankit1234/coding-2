class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1)return ;

        // j pointing to zero

        for(int i=j+1;i<n;i++){
            if(nums[i]!=0 and nums[j]==0){
                swap(nums[i],nums[j]);
                j++;
            }
        }

        return ;

        
    }
};