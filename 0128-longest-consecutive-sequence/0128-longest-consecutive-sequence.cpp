class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxcount=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                continue;
            }
            else{
                int num=nums[i];
            int left=mp.count(num-1)?mp[num-1]:0;
            int right=mp.count(num+1)?mp[num+1]:0;
            int length=left+right+1;
            maxcount=max(maxcount,length);
            mp[num]=length;
            mp[num-left]=length;
            mp[num+right]=length;
            cout<<left<<" "<<right<<endl;
            // cout<<num<<" "<<mp[num-left]<<" "<<mp[num+right]<<" "<<length<<endl;

            }
        }
        cout<<mp[1]<<" "<<mp[4]<<endl;
        return maxcount;
    }
};