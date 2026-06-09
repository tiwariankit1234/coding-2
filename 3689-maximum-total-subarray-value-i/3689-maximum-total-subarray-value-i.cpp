#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int x=*max_element(nums.begin(),nums.end());
        int y=*min_element(nums.begin(),nums.end());
        long long m=(ll)((ll)k*(ll)(x-y));
        return m;
    }
};