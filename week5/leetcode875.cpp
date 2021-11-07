class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPiles = 0;
        for(int pile: piles) {
            maxPiles = max(maxPiles, pile);
        }
        //从1开始，否则会出现divid by zero的错误
        int left = 1;
        int right = maxPiles;
        while(left < right) {
            int mid = (left + right) / 2;
            if(valid(piles, h, mid)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
    bool valid(vector<int>& piles, int h, int k) {
        int spendHours = 0;
        for(int pile: piles) {
            spendHours += (pile-1) / k + 1;
        }
        return spendHours <= h;
    }
};
