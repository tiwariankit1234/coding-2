class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int idx=-1,count=0;
        for(int i=1;i<n;i++){
          if(nums[i]<nums[i-1]){
            count++;
            idx=i;
          }
        }
        if(count==2)return false;
        if(idx==-1)return true;
        vector<int>temp;
        for(int i=idx;i<n;i++)temp.push_back(nums[i]);
        for(int i=0;i<idx;i++)temp.push_back(nums[i]);
        for(int i=1;i<n;i++){
            if(temp[i]<temp[i-1])return false;
        }
        return true;

    }
};