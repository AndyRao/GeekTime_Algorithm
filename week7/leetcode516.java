class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        s = " " + s;
        //申请 n + 2 防止 i + 1越界
        int[][] dp = new int[n + 2][n + 2];

        //遍历区间长度  j - i + 1 = l; j = i + l - 1 <= n; ==> i <= n - l + 1
        for(int l = 1; l <= n; l++) {
            for(int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                if(i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                if(s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[1][n];
    }
}
