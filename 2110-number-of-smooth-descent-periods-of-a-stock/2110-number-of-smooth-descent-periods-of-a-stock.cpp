#define ll long long 
class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n=nums.size();
        ll count=0;
        ll l=0,r=0;
        while(r<(n)){
            if(r>0 and nums[r]+1==nums[r-1]){
                count+=(r-l+1);   
            }
            else{
                l=r;
                count+=r-l+1;
            }
            r++;
        }
        return count;

    }
};