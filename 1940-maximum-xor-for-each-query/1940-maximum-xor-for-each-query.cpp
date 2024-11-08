class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int>prefixnum(n);
        int num=0;

        for(int i=0;i<n;i++){
            num^=nums[i];
        }
        prefixnum[0]=num;
        int i=1;
          int k=1;
          int mask = (1 << maximumBit) - 1;
        for(int i=n-1;i>0;i--){
            prefixnum[k++]=prefixnum[k-1]^nums[i];
        }

        for(int i=0;i<n;i++){
            prefixnum[i]^=mask;
        }

        return prefixnum;
    }
};