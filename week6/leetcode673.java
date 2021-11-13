class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        // dp[i] 代表以 i为结尾的最长递增子序列的长度
        // count[i] 代表以i为结尾最长递增子序列的个数
        int[] dp = new int[n];
        int[] count = new int[n];
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            count[i] = 1;
        }
        int maxLength = 0;
        int ans = 0;
        //这里必须从0开始, 在所有数字都相同的情况下不会漏掉1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if(dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                    
                }
               
            }
            if(dp[i] > maxLength) {
                maxLength = dp[i];
                ans = count[i];
            } else if(dp[i] == maxLength) {
                ans += count[i];
            }


        }
    
        return ans;



    }
}
