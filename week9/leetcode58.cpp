class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        //跳过所有空格
        while(i >= 0 && s[i] == ' ') i--;
        int start = i;
        while(i >= 0 && s[i] != ' ') i--;

        return start - i;
    }
};
