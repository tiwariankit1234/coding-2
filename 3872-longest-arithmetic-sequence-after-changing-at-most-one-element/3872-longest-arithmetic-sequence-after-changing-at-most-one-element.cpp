class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size(),ans=INT_MIN;
        vector<int>prefix(n,2),suffix(n,2);
        prefix[0]=1,suffix[n-1]=1;
        //at ending at index i
        for(int i=2;i<n;i++){
            if((nums[i]+nums[i-2])==2*nums[i-1]){
                prefix[i]=prefix[i-1]+1; 
                ans=max(ans,prefix[i]);
            }
            else{
                ans=max(ans,prefix[i-1]+1);
            }
        }
        // for(auto it:prefix)cout<<it<<" ";
        // cout<<endl;
        for(int i=n-3;i>=0;i--){
            if((nums[i]+nums[i+2])==(2*nums[i+1])){
                suffix[i]=suffix[i+1]+1;
               ans=max(ans,suffix[i]);
            }
            else{
                ans=max(ans,suffix[i+1]+1);
            }
        }
        // for(auto it:suffix){
        //     cout<<it<<" ";
        // }
        cout<<endl;
        for(int i=2;i<(n-1);i++){
            if((nums[i+1]-nums[i-1])%2==0){
                int d=(nums[i+1]-nums[i-1])/2;
                int left=0;
                if(nums[i-1]-nums[i-2]==d){
                    left+=prefix[i-1];
                }
                else{
                    left+=1;
                }
                int right=0;
                if(i+2<n and nums[i+2]-nums[i+1]==d){
                    right+=suffix[i+1];
                }
                else{
                    right+=1;
                }
                ans=max(ans,left+right+1);
            }
            }
        int d=nums[3]-nums[2];
        if((nums[0]+2*d)==nums[2]){
          ans=max(ans,prefix[0]+suffix[2]+1);
        }
        ans=max(ans,suffix[1]+1);
        ans=max(ans,prefix[n-2]+1);
        return ans;
    }
};