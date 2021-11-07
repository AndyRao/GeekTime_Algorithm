class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        int winner = 0;
        vector<int> counts(n + 1, 0);
        for(int i = 0; i < n; i++) {
            counts[persons[i]]++;
            if(counts[persons[i]] < counts[winner]) {
                continue;
            }
            winner = persons[i];
            timeToWinner.push_back(Vote(times[i], winner));
        }
    }
    
    int q(int t) {
        //二分， 找到最后一个<= t时刻的winner
        int left = 0;
        int right =  timeToWinner.size() - 1;
        while(left < right) {
            int mid = (left + right + 1) / 2;
            if(timeToWinner[mid].time <= t) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return timeToWinner[right].winner;       

    }
private:
    struct Vote {
        int time;
        int winner;
        Vote(int time, int winner): time(time), winner(winner) {}
    };
    vector<Vote> timeToWinner;
    
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
