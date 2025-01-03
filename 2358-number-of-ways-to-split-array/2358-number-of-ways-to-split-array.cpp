#define ll long long 
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        ll totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
          ll prefixsum=0;
        for(int i=0;i<(n-1);i++){
            prefixsum+=nums[i];
            if(prefixsum>=(totalsum-prefixsum)){
                count++;
            }
        }
        return count;
    }
};