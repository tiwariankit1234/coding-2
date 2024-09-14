class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // here we are going to see the maximum largest element subarray
        // find maximum element and its index
          
            int n=nums.size();
        int maxelement=-1;
        int index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxelement){
                maxelement=nums[i];  
                index=i;
            }
        }
       
        
        int currentstreak=0,maxstreak=1,right=index;
        
        while(right<n){
            if(nums[right]==maxelement){
                currentstreak++;
                maxstreak=max(currentstreak,maxstreak); 
            }
            else{
                currentstreak=0;
            }
            right++;
        }
        
   
    return maxstreak;
    }
};