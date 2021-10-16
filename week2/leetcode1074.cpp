class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            vector<int> sum(n);
            for(int j = i; j < m; j++) {
                for(int k = 0; k < n; k++) {
                    sum[k] += matrix[j][k];
                }
                count += subarraySum(sum, target);
            }
        }
        return count;

    }
private: 
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();

        unordered_map<int, int> counts;
        int pre = 0;
        int ans = 0;
        //不要忘了下面这一行
        counts[0] = 1;
        for(int i = 0; i < len; i++) {
            pre += nums[i];
            int temp = pre - k;
            ans += counts[temp];
            counts[pre]++;
        }
        return ans;
    }
};
