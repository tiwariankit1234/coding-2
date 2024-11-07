class Solution {
public:
    int largestCombination(vector<int>& nums) {
        vector<int>ans(32,0);
        int count=0,value=0;
        for(int num:nums){
            count=0;
            while(num>0){
               
                if(num%2==1){
                    value=1;
                }
                else{
                    value=0;
                }
                ans[count]+=value;
                count++;
                num/=2;
            }
        }
        int size=0;
        for(auto it:ans){
          size=max(size,it);
        }
        return size;

    }
};