class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int m = triangle.size();
        int n = triangle.get(m - 1).size();
        //dp[i][j] 代表以i, j坐标为终点路径最小和
        int[][] dp = new int[m][n];
        dp[0][0] = triangle.get(0).get(0);

        for(int i = 1; i < m; i++) {
            //每一行最左边的点只能从上一行最左边的点到达
            dp[i][0] = dp[i-1][0] + triangle.get(i).get(0);
            for(int j = 1; j < i; j++) {
                dp[i][j] = Math.min(dp[i-1][j], dp[i-1][j-1]) + triangle.get(i).get(j);    
            }
            //每一行最右边的点只能从上一行最右边的点到达
            dp[i][i] = dp[i-1][i-1] + triangle.get(i).get(i);
        }
        

        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++) {
           ans = Math.min(ans, dp[m-1][i]); 
        }
        return ans;
    }
}
