#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> nums;
    int x;
    int n;
    cin >> n;
    cin >> x;
    nums[x] = 1;
    for(int i = 2; i <= n; ++i){
        cin >> x;
        auto after = nums.lower_bound(x); 
        if(after == nums.begin()){
            cout <<abs(after->first - x)<< ' ' << after->second << endl;
        }
        else{
            auto first = after; 
            --first; 
            if(after == nums.end()){
                cout << abs(first->first - x)<< ' ' << first->second << endl;
            }
            else{
                auto choice = abs(first->first - x) <= abs(after->first - x) ? first : after;
                cout << abs(choice->first - x) << ' ' << choice->second << endl;
            }
        }
        nums[x] = i;
    }

    return 0;
}

