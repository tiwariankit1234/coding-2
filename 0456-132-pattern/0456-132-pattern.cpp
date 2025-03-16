class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int l=nums[0];
        map<int,int>r;
        if(n<3) return false;
        
        for(int i=n-1;i>=2;i--)
        {
            r[nums[i]]++;
        }
        for(int i=1;i<n-1;i++)
        {
          int f=l;
          
          auto it2=r.upper_bound(f);
          int f2=it2->first;
          if( it2!=r.end() && f<f2 && f2<nums[i])
          {
            return true;
          }
          
          else
          {
            l=min(l,nums[i]);
            r[nums[i+1]]--;
            if(r[nums[i+1]]==0) r.erase(nums[i+1]);
          }
        }
        return false;
    }
};