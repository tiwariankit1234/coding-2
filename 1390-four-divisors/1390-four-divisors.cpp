class Solution {
public:
void possible(int num,vector<int>&nums,int &sum){
    int x=sqrt(num);
    int count=0;
    for(int i=1;i<=x;i++){
        if((num%i)==0){
            int t=num/i;
            if(t!=i)count+=2;
            else count+=1;
        }
    }
    if(count==4){
        for(int i=1;i<=x;i++){
            if((num%i)==0){
                int t=num/i;
            if(t!=i)sum+=t+i;
            else sum+=t;
            }
        }
    }
}
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int num:nums){
            (possible(num,nums,sum));
            
        }
        return sum;
    }
};