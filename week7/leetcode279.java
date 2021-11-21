class Solution {
    public int numSquares(int n) {
        //f[i] 表示 和为i 的完全平方数的最少数量
        int[] dp = new int[n + 1];
        for(int i = 0; i <= n; i++) {
            dp[i] = Integer.MAX_VALUE;
        }
        dp[0] = 0; 
        int right = (int) Math.sqrt(n);
        for(int i = 1; i <= right; i++) {
            for(int j = i * i; j <= n; j++) {
                dp[j] = Math.min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
}
