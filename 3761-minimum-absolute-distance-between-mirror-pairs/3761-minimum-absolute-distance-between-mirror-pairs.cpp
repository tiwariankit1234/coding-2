class Solution {
public:
int f(int n) {
        int previousnum=0,currentnumber=0;
        int k=n;
        while(k>0){
            int currentdigit=k%10;
            currentnumber=previousnum*10+currentdigit;
            k=k/10;
            previousnum=currentnumber;
        }
        return currentnumber;
}
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        mp[nums[n-1]]=n-1;
        for(int i=n-2;i>=0;i--){
        int reversenum=f(nums[i]);
        if(mp.find(reversenum)!=mp.end()){
            ans=min(ans,abs(i-mp[reversenum]));
        }
        mp[nums[i]]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};