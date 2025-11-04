class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0;
           for(int i=0;i<n;i++){
            int target=-1*nums[i];
           if(i>0 and nums[i]==nums[i-1]){
               continue;
            }
         int j=i+1,k=n-1;
         cout<<i<<" "<<j<<" "<<k<<endl;
         cout<<"bahar wala"<<endl;
          while( j<k ){
            int sum=nums[j]+nums[k];
            if(sum>target){
                k--;
            }
            else if(sum==target){
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                cout<<i<<" "<<j<<" "<<k<<" "<<endl;
                cout<<"andhar wala"<<endl;
                while(j<k and nums[j]==nums[j-1])j++;
            }
            else{
                j++;
            }
       } 
    }
      return ans;
    }
};