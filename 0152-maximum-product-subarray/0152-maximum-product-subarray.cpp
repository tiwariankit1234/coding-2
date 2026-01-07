class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxproduct=INT_MIN,prevproduct=1;
        for(int i=0;i<n;i++){

            if(prevproduct==0){
            int curr=1*nums[i];
            maxproduct=max(maxproduct,curr);
            prevproduct=curr;
            }
            else{
                int curr=prevproduct*nums[i];
                maxproduct=max(maxproduct,curr);
                prevproduct=curr;
            }
        }
         prevproduct=nums[n-1];
         maxproduct=max(maxproduct,prevproduct);
         for(int i=n-2;i>=0;i--){
            if(prevproduct==0){
            int curr=1*nums[i];
            maxproduct=max(maxproduct,curr);
            prevproduct=curr;
            }
            else{
                int curr=prevproduct*nums[i];
                maxproduct=max(maxproduct,curr);
                prevproduct=curr;
            }
         }
         return maxproduct;
    }
};