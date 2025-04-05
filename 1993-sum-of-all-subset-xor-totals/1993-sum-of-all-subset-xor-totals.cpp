class Solution {
public:
int totalsum=0;
void f(int i,vector<int>& nums,int sum){
    int n=nums.size();
    if(i==n){
      totalsum+=sum;
       return ;
    }
    // take dp 
    int newsum=nums[i]^sum;
    f(i+1,nums,newsum);
    // nottake dp
    f(i+1,nums,sum);
    return ;
}
    int subsetXORSum(vector<int>& nums) {
      f(0,nums,0);
      return totalsum;
    }
};