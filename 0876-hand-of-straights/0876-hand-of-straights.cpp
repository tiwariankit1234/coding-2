class Solution {
public:
    bool isNStraightHand(vector<int>&nums, int k) {
        int n=nums.size();
          map<int,int>mp;
          for(auto it:nums){
            mp[it]++;
          }
          int count=0;
          if(n%k!=0)return false;
          for(auto& [num,freq]:mp){
            bool flag=true;
            while(freq>0){
                bool flag=false;
                for(int curr=num;curr<=(num+k-1);curr++){
                    if(mp[curr]<=0)return false;
                    mp[curr]--;   
                }
                if(!flag)count++;
              
            }
    
          }
        
          return count==(n/k);
    }
};