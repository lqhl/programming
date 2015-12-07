const int dx[] = { 0, 1, 0,-1};
const int dy[] = { 1, 0,-1, 0};

class Solution {
private:
    int n, m;
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        vector<pair<int, int>> q;
        int head = 0;
        q.push_back(make_pair(i, j));
        bool surrounded = true;
        while (head < q.size()) {
            int x = q[head].first, y = q[head].second;
            head++;
            for (int k = 0; k < 4; k++) {
                int tx = x + dx[k];
                int ty = y + dy[k];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                    surrounded = false;
                } else if (board[tx][ty] == 'O' && !visited[tx][ty]) {
                    visited[tx][ty] = true;
                    q.push_back(make_pair(tx, ty));
                }
            }
        }
        if (surrounded)
            for (auto& each : q)
                board[each.first][each.second] = 'X';
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 'O' && !visited[i][j])
                    bfs(board, visited, i, j);
    }
};
