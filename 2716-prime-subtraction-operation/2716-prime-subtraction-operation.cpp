class Solution {
public:

bool isPrime(int i){
int num=sqrt(i);
for(int k=num;k>=2;k--){
    if(i%k==0)return false;
}
return true;
}

bool prime(int index,vector<int>& nums,int previousindex){
    int n=nums.size();
    int previouselement=0;
   if(previousindex==-1)
   previouselement=0;
   else
   previouselement=nums[previousindex];
   


    for(int i=nums[index]-1;i>=2;i--){
        if(isPrime(i) and ((nums[index]-i)>previouselement)){
             cout<<i<<" "<<index<<endl;
            nums[index]=nums[index]-i;
            // cout<<nums[index]<<" "<<nums[index-1]<<endl;
            return true;
        }
    }
    return false;
}



    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            prime(i,nums,i-1);
        }

        for(auto it:nums){
            cout<<it<<" ";
        }
       for(int i=1;i<n;i++){
        if(nums[i]<=nums[i-1]){
        return false;
        }
       }
        return true;
    }
};