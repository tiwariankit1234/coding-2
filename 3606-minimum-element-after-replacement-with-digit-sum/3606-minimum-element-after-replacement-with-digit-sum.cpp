class Solution {
public:
  
  int sumofdigits(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num=num/10;
    }
    return sum;
  }

    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int num:nums){
            ans=min(ans,sumofdigits(num));
        }
        return ans;
    }
};