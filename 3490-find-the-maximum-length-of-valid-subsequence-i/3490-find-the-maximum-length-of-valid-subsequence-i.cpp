class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }
        if(n==2)return 2;
        int maxsubs=1;
        vector<int>dp(n,1);
        // for(auto it:nums)
        // cout<<it<<" ";
        cout<<endl;
        int previdxzero=-1,previdxone=-1;
        if(nums[0]==0)
         previdxzero=0;
        else
        previdxone=0;
        for(int i=1;i<=n-1;i++){
            if(nums[i]==1 and previdxzero!=-1){
                dp[i]=dp[previdxzero]+1;
                maxsubs=max(dp[i],maxsubs);
                previdxone=i;
            }
            else if(nums[i]==0 and previdxone!=-1){
              dp[i]=dp[previdxone]+1;
                maxsubs=max(dp[i],maxsubs);
                previdxzero=i;
            }
            
     
        }
       

    int zerosequence=0;
    int onesequence=0;
    for(auto i:nums){
        if(i==0)
        zerosequence++;
        else
        onesequence++;
    }
    maxsubs=max(max(zerosequence,onesequence),maxsubs);

 return maxsubs;
        
    }
};