class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cs;
        for(char c: s) {
            cs[c] += 1;
        }
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(cs[s[i]] == 1) return i;
        }
        return -1;
    }
};
