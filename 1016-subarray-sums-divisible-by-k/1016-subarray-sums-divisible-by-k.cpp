class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int currentsum=0,count=0;
        for(int i=0;i<n;i++){
            currentsum+=nums[i];
            
            if(mp.find(((currentsum-k)%k+k)%k)!=mp.end()){
                count+=mp[((currentsum-k)%k+k)%k];
            }
            mp[((currentsum-k)%k+k)%k]+=1;
          
            cout<<endl;
        }
        return count;
    }
};