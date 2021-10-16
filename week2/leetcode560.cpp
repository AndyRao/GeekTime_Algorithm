class Solution {
public:
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
