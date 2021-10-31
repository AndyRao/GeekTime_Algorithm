class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = 'S';
                q.push({i, 0});
            }
            if(board[i][n-1] == 'O') {
                board[i][n-1] = 'S';
                q.push({i, n-1});
            }
            
        }

        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O') {
                board[0][i] = 'S';
                q.push({0, i});
            }
            if(board[m-1][i] == 'O') {
                board[m-1][i] = 'S';
                q.push({m-1, i});
            }
            
        }
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, 1, -1, 0};
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || board[nx][ny] != 'O') {
                    continue;
                }
                board[nx][ny] = 'S';
                q.push({nx, ny});
            }
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'S') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

            }


    }
};
