class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxproduct=INT_MIN,product=1;
        for(int i=0;i<n;i++){
            product=product*nums[i];
            maxproduct=max(maxproduct,product);
            if(product==0){
                maxproduct=max(maxproduct,product);
                product=1;
            }
        }
         product=1;
        for(int i=n-1;i>=0;i--){
            product=product*nums[i];
            maxproduct=max(product,maxproduct);
            if(product==0){
                maxproduct=max(maxproduct,product);
                product=1;
            }
        }
        return maxproduct;
    }
};