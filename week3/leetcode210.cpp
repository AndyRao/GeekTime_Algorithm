class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        to = vector<vector<int>>(numCourses, vector<int>());
        indegree = vector<int>(numCourses, 0);
        //建立出边数组
        for(vector<int>& p: prerequisites) {
            int ai = p[0];
            int bi = p[1];
            to[bi].push_back(ai);
            indegree[ai]++;
        }
        //将所有入度为0的点入队列
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        //bfs遍历
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(int y: to[x]) {
                indegree[y]--;
                //注意这里不需要判重，因为如果有环存在，入度不可能变成0，也就不会被加入到队列中
                if(indegree[y] == 0) {
                    q.push(y);
                }
            }

        }
        if(ans.size() == numCourses) return ans;
        return {};


    }
private:
    vector<vector<int>> to;
    //记录每个点的入度
    vector<int> indegree;

    
};
