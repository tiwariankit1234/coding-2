class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s(nums.begin(),nums.end());
        int count=0,maxcount=0;
        for(int num:s){
            if(s.find(num-1)!=s.end())continue;
            count=0;
            while(s.find(num)!=s.end()){
                count++;
                num=num+1;
            }
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};