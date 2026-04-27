#define ll long long
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        ll totalsum=0;
        for(auto it:nums)totalsum+=it;
        ll sum1=0,sum2=0;
        ll i=0;
        while(nums[i]<nums[i+1]){
          sum1+=nums[i];
          i++;
        }
        i++;
        while(i<nums.size()){
            sum2+=nums[i];
            i++;
        }
        // cout<<sum1<<" "<<sum2<<endl;
        if(sum1>sum2)return 0;
        else if(sum2>sum1)return 1;
        else
        return -1;

    }
};