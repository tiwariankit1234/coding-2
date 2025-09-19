class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
       int countzero=0,zeroidx=-1,productwithoutzero=1;
       for(int i=0;i<n;i++){
        if(nums[i]==0){
            zeroidx=i;
            countzero++;
        }
        else{
          productwithoutzero*=nums[i];
        }

       }
     if(countzero==0){
        for(int i=0;i<n;i++){
            nums[i]=(productwithoutzero)/nums[i];
        }
     }
     else if(countzero>=2){
        for(int i=0;i<n;i++){
            nums[i]=0;
        }
     }
     else if(countzero==1){
        for(int i=0;i<n;i++){
            if(i==zeroidx){
                nums[i]=productwithoutzero;
            }
            else{
                nums[i]=0;
            }
        }
     }
     return nums;
    }
};