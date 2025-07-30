class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // here we are going to see the maximum largest element subarray
        // find maximum element and its index
          
         

        int n=nums.size(),maxelement=*max_element(nums.begin(),nums.end());

        // beacause and decrese it
     
       int i=0,j=0;
       int maxsize=1;
       while(i<n){
          if(nums[i]==maxelement){
            j=i;
            while(j<n and nums[j]==maxelement){
                 maxsize=max(maxsize,(j-i+1));
                 j++;
            }
            i=j;
          }
          else{
            i++;
          }

       }
    
    return maxsize;
    }
};