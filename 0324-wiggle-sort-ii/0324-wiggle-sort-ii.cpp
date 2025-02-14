class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans(n,0);
        int j=n-1;
        for(int i=0;i<n;i++){
            if(i&1){
                ans[i]=nums[j--];
            }
        }
        for(int i=0;i<n;i++){
            if(!(i&1)){
                ans[i]=nums[j--];
            }
        }
         nums=ans;
         return ;
    }
};