class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        multimap<int, int>  map;
        for(int i = 0; i < n; i++) {
            if(map.size() < k) {
               map.insert({nums[i], i}); 
               continue;
            }
            auto it = map.end();
            it--;
            ans.push_back(it->first);
            map.erase(map.find(nums[i - k]));
            map.insert({nums[i], i});
           
        }
        auto it = map.end();
        it--;
        ans.push_back(it->first);
        return ans;
    }
};
