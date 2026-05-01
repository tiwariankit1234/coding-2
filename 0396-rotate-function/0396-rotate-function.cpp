// since hame rotation n-1 karni hain
// maxsum ko INT_MIN se initialise karna hain
// aur har ek element ke last element ko subtract karna hain
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int maxsum=INT_MIN;
        int previousum=0;
        for(int i=0;i<n;i++){
            previousum+=(i*nums[i]);
        }
        maxsum=max(maxsum,previousum);

        for(int i=1;i<=(n-1);i++){
        int x=previousum+totalsum-n*nums[n-1-(i-1)];
       
        maxsum=max(maxsum,x);
        // cout<<i<<" "<<x<<" "<<previousum<<" "<<totalsum<<endl;
        previousum=x;
        }
        return maxsum;
    }
};