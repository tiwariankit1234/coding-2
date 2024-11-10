class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = 0;
        vector<int> f(32,0);
        int val = 0;
        int ans = INT_MAX;
        while(end<n){
            int temp = nums[end];
            for(int i=0;i<32;i++){
                int x = 1<<i;
                if((temp&x)){
                    f[i]++;
                    if(f[i]==1) val+=x;
                }
            }
            while(val>=k && start<end){
                int temp = nums[start];
                for(int i=0;i<32;i++){
                    int x = 1<<i;
                    if((temp&x)){
                        f[i]--;
                        if(f[i]==0){
                            val-=x;
                        }
                    }
                }
                if(val<k){
                    for(int i=0;i<32;i++){
                        int x = 1<<i;
                        if((temp&x)){
                            f[i]++;
                            if(f[i]==1) val+=x;
                        }
                    }
                    break;
                }
                start++;
            }
            if(val>=k){
                // cout << end << " " << start << " " << val << endl;
                ans = min(ans,end-start+1);
            }
            end++;
        }
        return ans==INT_MAX?-1:ans;
        
    }
};