class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int right = 0;
        int left = 0;
        for(int weight: weights) {
            left = max(left, weight);
            right += weight;
        }
        while(left < right) {
            int mid = (right + left) / 2;
            if(validate(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }

        }
        return right;
    }
    bool validate(vector<int>& weights, int days, int load) {
        int daysNeed = 1;
        int currentWeight = 0;
        for(int weight: weights) {
            if(weight + currentWeight <= load) {
                currentWeight += weight;
            } else {
                daysNeed++;
                currentWeight = weight;
            }
        }
        return daysNeed <= days;
        
    }
};
