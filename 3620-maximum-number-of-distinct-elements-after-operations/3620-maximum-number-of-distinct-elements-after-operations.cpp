class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int last=nums[0]-k;
        
        int count=0;
        for(int i=0;i<n;i++){
            int valend=nums[i]+k;
            int  valstart=nums[i]-k;
             if(last<valstart){
                last=max(valstart,last);
                last++;
                count++;
             }
            
           else if(last>=valstart and last<=valend){
                count++;
                last++;
            }
        
        }
        return count;
    }
};