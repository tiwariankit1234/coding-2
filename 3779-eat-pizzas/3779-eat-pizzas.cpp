#define ll long long
class Solution {
public:
    long long maxWeight(vector<int>& nums) {
        ll n = nums.size();
        sort(nums.begin(), nums.end());
        ll sum = 0;
        int idx = -1;
        int k = n/4;
        int temp1=k/2+k%2,temp2=k-temp1;

        // cout<<temp1<<endl;
      
        for (int i = n - 1; i >= 0; i--) {
            if (temp1 > 0) {
                sum += nums[i];
                temp1--;
            }
            if (temp1 == 0) {
                idx = i;
                break;
            }
        }
        idx -= 2;
        // cout<<temp2<<endl;
        while (idx >= 0) {
            if (temp2 > 0) {
                sum += nums[idx];
                idx -= 2;
               temp2-=1;
            }
            if(temp2==0)
            break;
        }
        return sum;
    }
};