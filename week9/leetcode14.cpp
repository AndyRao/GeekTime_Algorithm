class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int n = strs.size();
        for(int i = 1; i < n; i++) {
            prefix = longestCPTwo(prefix, strs[i]);
            if(prefix == "") break;
        }
        return prefix;
    }
private:
    string longestCPTwo(string &a, string &b) {
        int alen = a.size();
        int blen = b.size();
        int l = min(alen, blen);
        int i = 0;
        while(i < l && a[i] == b[i]) i++;
        return a.substr(0, i);
    }
};
