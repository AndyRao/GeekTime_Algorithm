class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelsType;
        for(char j: jewels) {
            jewelsType.insert(j);
        }
        int ans = 0;
        for(char s: stones) {
            if(jewelsType.find(s) == jewelsType.end()) continue;
            ans++;
        }
        return ans;
    }
};
