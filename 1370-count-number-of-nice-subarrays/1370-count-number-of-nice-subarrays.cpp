class Solution {
public:
 int f(vector<int>& nums,int k){
        if(k<0)return 0;
           int n=nums.size();
        int l=0,r=0;
        int count=0,sum=0,odd=0;
        while(r<n){
          if((nums[r]%2)!=0)odd++;
          while(odd>k and l<n){
           if((nums[l]%2)!=0)odd--;
           l++;
          }
          count+=(r-l+1);
          r++;
        }
        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int count1=f(nums,k);
        int count2=f(nums,k-1);
        return (count1-count2);
    }
};