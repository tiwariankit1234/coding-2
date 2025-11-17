class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,previdx=-1;
        while(i<n){
           if(nums[i]==1 and previdx==-1){
            previdx=i;
           }
           else if(nums[i]==1 and (i-previdx-1)>=k){
            previdx=i;
           }
           else if(nums[i]==1 and (i-previdx-1)<k){
            return false;
           }
        //    cout<<previdx<<" "<<i<<endl;
           i++;
        }
        return true;
    }
};