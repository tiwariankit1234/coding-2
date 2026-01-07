class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        if (n == 0) {
            throw new IllegalArgumentException();
        }
        
        int curMax = nums[0];
        int curMin = nums[0];
        int ans = curMax;
        
        for (int i = 1; i < n; i++) {
            int tmp = curMax;
            curMax = Math.max(tmp*nums[i], Math.max(curMin*nums[i], nums[i]));
            curMin = Math.min(tmp*nums[i], Math.min(curMin*nums[i], nums[i]));
            
            ans = Math.max(ans, curMax);
        }

        return ans;
    }
}