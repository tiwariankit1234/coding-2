class Solution {
public:
    bool isNStraightHand(vector<int>&nums, int k) {
        int n=nums.size();
        if((n%k)!=0)return false;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            int num=it->first;
          
            while(mp[num]>0){
                mp[num]--;
            for(int j=1;j<=(k-1);j++){
                if(mp.find(num+j)!=mp.end() and mp[num+j]>0){
                    mp[num+j]--;
                   
                }
                else{
                    return false;
                }
            }
        }
        }
        return true;

    }
};