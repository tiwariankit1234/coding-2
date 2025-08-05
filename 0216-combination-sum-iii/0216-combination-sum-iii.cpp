class Solution {
public:
void f(int idx,int k,int n,vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums){
   int m=nums.size();
//    cout<<idx<<" "<<k<<" "<<n<<" "<<nums[idx]<<endl;
   if(k==0){
    if(n==0){
        ans.push_back(temp);
    }
    return ;
 }
   if(idx==nums.size()){
    return ;
   }
 
 // take
 if(n-nums[idx]>=0 and k>0){
    temp.push_back(nums[idx]);
 f(idx+1,k-1,n-nums[idx],temp,ans,nums);
 temp.pop_back();
 }
 f(idx+1,k,n,temp,ans,nums);
 return ;
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums,temp;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        vector<vector<int>>ans;
     f(0,k,n,temp,ans,nums);
     return ans;
    }
};