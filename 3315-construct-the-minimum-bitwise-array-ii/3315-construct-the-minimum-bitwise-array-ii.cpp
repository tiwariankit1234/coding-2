class Solution {
public:
int f(int num){
     int k=-1;
        for(int i=0;i<31;i++){
        
            //check if the i-th bit is set
            if((num&(1<<i))==0) {
               k=i;
               break;
            }
           
        }
        

    if(k!=-1 and (k-1)<31){
            num=num^(1<<(k-1));
        }
        return num;
}
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==2){
                nums[i]=-1;
                continue;
            }
            nums[i]=f(nums[i]);
        }
        return nums;
    }
};