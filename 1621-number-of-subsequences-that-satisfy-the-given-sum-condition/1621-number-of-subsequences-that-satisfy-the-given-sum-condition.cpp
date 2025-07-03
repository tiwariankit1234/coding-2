#define ll long long 
int mod=1e9+7;
vector<int>arr(1e5,0);



class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
       int n=nums.size();
       vector<int>pow2(n,1);
       for(int i=1;i<n;i++){
        pow2[i]=(pow2[i-1]*2)%mod;
       }

        sort(nums.begin(),nums.end());
       
        int i=0,j=0;
      int count=0,sum=0;
        while(i<n){
           ll newtarget=target-nums[i];
            
            if(newtarget<nums[i])return count;
            int idx=upper_bound(nums.begin()+i,nums.end(),newtarget)-nums.begin();          
            
            int newcount=0;
            if(idx<=n){
                idx--;
                count=count%mod+pow2[idx-i];
            }
         
            //    cout<<count<<" "<<i<<" "<<idx<<" "<<nums[i]<<" "<<newtarget<<endl;
            i++;
            
        }

        return count;
    }
};