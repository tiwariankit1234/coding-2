class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //        for(int k=j+1;k<n;k++){
        //         ans=min(ans,nums[0]+nums[j]+nums[k]);
        //        }
        //     }
        // }
        sort(nums.begin()+1,nums.end());
        ans=min(ans,nums[0]+nums[1]+nums[2]);
        int minelement1=INT_MAX,minidx=-1;
        for(int i=1;i<n;i++){
            if(nums[i]<minelement1){
                minelement1=nums[i];
                minidx=i;
            }
        }
        int minelement2=INT_MAX;
        for(int i=1;i<n;i++){
            if(nums[i]<minelement2 and i!=minidx){
                minelement2=nums[i];
            }
        }
        return nums[0]+minelement1+minelement2;
    }
};