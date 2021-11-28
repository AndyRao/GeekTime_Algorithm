class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        fa = vector<int>(m * n, 0);
        for(int i = 0; i < m*n; i++) {
            fa[i] = i;
        }
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, 1, -1, 0};
        int outside = m * n;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(grid[x][y] == '0') {
                    continue;
                }
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                      continue;
                    } else {
                        if(grid[nx][ny] == '1') {
                            unionSet(num(x,y), num(nx, ny));
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) { 
                //注意不要忘记了grid[x][y] != '0'这个条件
                if(fa[num(x,y)] == num(x,y) && grid[x][y] != '0') {
                    ans++;
                }
            }
        }
        return ans;
        
    }
private: 
    int m;
    int n;
    vector<int> fa;
    int num(int x, int y) {
        return x * n + y;
    }
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    void unionSet(int x, int y) {
        x = find(x), y = find(y);
        if(x != y) {
            fa[x] = y;
        }
    }
};
