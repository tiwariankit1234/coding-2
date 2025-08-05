class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
       
        multiset<int>s;
        int l=0,r=0,n=nums.size(),maxsize=INT_MIN;
            while(r<n){
                s.insert(nums[r]);
                 if((*s.rbegin()-*s.begin())<=k){
                    // cout<<l<<" "<<r<<endl;
                    maxsize=max(maxsize,r-l+1);
                 }
               
                    while((*s.rbegin())-(*s.begin())>k){
                        // cout<<*s.begin()<<" "<<*s.rbegin()<<" "<<l<<" "<<r<<endl;
                  s.erase(s.find(nums[l]));
                        l++;
                    }
                    maxsize=max(maxsize,r-l+1);

                 
                r++;
            }
            return maxsize;
    }
};