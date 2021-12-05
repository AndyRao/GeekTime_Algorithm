class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int l = findNext(s, 0);
        int r = findPrev(s, n - 1);
        while(l < r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l = findNext(s, l + 1);
            r = findPrev(s, r - 1);
        } 
        return s;
    }
private: 
    bool isLetter(char ch) {
        return ch >= 'a'&& ch <='z' || ch >= 'A' && ch <= 'Z';
    }
    int findNext(string& s, int index) {
        while(index < s.size() && !isLetter(s[index])) index++;
        return index;
    }

    int findPrev(string& s, int index) {
        while(index >= 0 && !isLetter(s[index])) index--;
        return index;
    }
};
