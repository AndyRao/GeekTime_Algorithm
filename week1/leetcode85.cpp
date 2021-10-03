class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        vector<int> heights(matrix[0].size(), 0);
        int maxAreas = 0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if((matrix[i][j] - '0') == 1) {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxAreas = max(maxAreas, largestRectangleArea(heights));
        }
        return maxAreas;
    }


private:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        heights.push_back(0);
        for(int height: heights) {
            int accHeight = 0;
            while(!s.empty() && s.top().height >= height) {
                accHeight += s.top().width;
                ans = max(ans, s.top().height * accHeight);
                s.pop();
            }
            s.push(rec{accHeight+1, height});
        }
        return ans;
        
    }
    struct rec {
        int width;
        int height;
    };
    stack<rec> s;
};
