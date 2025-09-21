#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
      ll maxelement=*max_element(nums.begin(),nums.end()),minelement=*min_element(nums.begin(),nums.end());
      return (k)*(maxelement-minelement);
    }
};