class Solution {
 public:
//     int longestSubarray(vector<int>& nums) {
//         // here we are going to see the maximum largest element subarray
//         // find maximum element and its index
          
//             int n=nums.size();
//         int maxelement=-1;
//         int index=-1;
//         for(int i=0;i<n;i++){
//             if(nums[i]>maxelement){
//                 maxelement=nums[i];  
//                 index=i;
//             }
//         }
       
        
//         int currentstreak=0,maxstreak=1,right=index;
        
//         while(right<n){
//             if(nums[right]==maxelement){
//                 currentstreak++;
//                 maxstreak=max(currentstreak,maxstreak); 
//             }
//             else{
//                 currentstreak=0;
//             }
//             right++;
//         }
        
   
//     return maxstreak;
//     }

//     // learning always do not think of sliding window for size calculation subaaray
//     // if you can do it by single variable
//     // agar multiple subarray ho toh single element se ho sakta hain

// };

 int longestSubarray(vector<int>& nums) {
       int mx=-1,n=size(nums);
        for(auto& el : nums)
            mx=max(el, mx);
        
        int i=0,j=0,res=1;
        while(j<n){
            if(nums[j]==mx){
                res=max(res, j-i+1);
                j++;
            }
            else{
                j++;
                i=j;
            }
        }
        
        return res;
    }
};  

