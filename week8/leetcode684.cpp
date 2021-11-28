class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        fa = vector<int>(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        for(const vector<int>& edge: edges) {
            int x = edge[0];
            int y = edge[1];
            if(find(x) == find(y)) {
                return edge;
            }
            unionSet(x, y);
        }
        return {};
    }

private:
    vector<int> fa;

    int find(int x) {
        if(x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    void unionSet(int x, int y) {
        x  = find(x), y = find(y);
        if(find(x) == find(y)) return;
        fa[x] = y;
        
    }
};
