#define ll long long 
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll n=nums1.size(),m=nums2.size();
        ll count1=0,count2=0,sum1=0,sum2=0;
 
        for(int i=0;i<n;i++){
            if(nums1[i]==0)
            count1++;
            else{
                sum1+=nums1[i];
            }
        }
        for(int i=0;i<m;i++){
            if(nums2[i]==0)
            count2++;
            else{
                sum2+=nums2[i];
            }
        }
    // three cases 
    if(count1==0 and count2==0){
        if(sum1!=sum2)return -1;
         return sum1;
    }
    else if(count1==0 ||count2==0){
        if(count1==0){
            
            if(count2+sum2>sum1)return -1;
            return sum1;
        }
        else {
      
            if(count1+sum1>sum2)return -1;
            return sum2;
        }
    }
    else{
    
       
          return max(sum1+count1,sum2+count2);
    }
      return 0;
    }
};