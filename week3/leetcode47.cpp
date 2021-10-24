class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(n, false);
        sort(nums.begin(), nums.end());
        recr(nums, path, ans, used);
        return ans;
    }

    void recr(vector<int>& nums, vector<int>& path, vector<vector<int>>& ans, vector<bool>& used) {
        if(path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            //used[i-1] == false 说明 i -1 对应位置的数字在后面可以被再次选择，是一个被回退的分支
            if(used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) continue;
            path.push_back(nums[i]);
            used[i] = true;
            recr(nums, path, ans, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
