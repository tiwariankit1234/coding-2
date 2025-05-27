class Solution {
public:
   

    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int l = 2, h = 2 * limit;
       int ans=INT_MAX;
       
      
      vector<int>prefixsum(2*1e5+1,0);
      int i=0;
  
      while(i<(n/2)){
        int left=nums[i],right=nums[n-i-1];
        int minsum=min(left,right)+1;
        int maxsum=max(left,right)+limit;
           prefixsum[2]+=2;
         prefixsum[minsum]+=-1;
         prefixsum[maxsum+1]+=1;
         prefixsum[left+right]+=-1;
         prefixsum[left+right+1]+=1;
         i++;
      }
      for(int j=2;j<prefixsum.size();j++){
        prefixsum[j]+=prefixsum[j-1];
      }
      for(int j=2;j<=(2*limit);j++){
        ans=min(prefixsum[j],ans);
      }
      

    

        return ans;
    }
};