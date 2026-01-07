class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0),suffix(n,0);
        int maxproduct=INT_MIN;
        prefix[0]=nums[0];
        maxproduct=max(maxproduct,prefix[0]);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
            if(prefix[i-1]==0)prefix[i]=1*nums[i];
            else
            prefix[i]=prefix[i-1]*nums[i];
            maxproduct=max(maxproduct,prefix[i]);
        }
        suffix[n-1]=nums[n-1];
        maxproduct=max(maxproduct,suffix[n-1]);
        for(int i=n-2;i>=0;i--){
            if(suffix[i+1]==0){
            suffix[i]=1*nums[i];
            }
            else{
                suffix[i]=suffix[i+1]*nums[i];
            }
            maxproduct=max(maxproduct,suffix[i]);
        }
        for(int i=0;i<n;i++){
            maxproduct=max(maxproduct,nums[i]);
        }
        return maxproduct;
        
        

    }
};