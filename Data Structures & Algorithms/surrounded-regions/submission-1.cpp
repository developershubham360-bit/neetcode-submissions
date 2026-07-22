class Solution {
public:
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}
    };

    void dfs(int r, int c, vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            board[r][c] != 'O')
            return;

        board[r][c] = '#';

        for (auto &[dr, dc] : directions) {
            dfs(r + dr, c + dc, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            dfs(i, 0, board);
            dfs(i, cols - 1, board);
        }

        for (int j = 0; j < cols; j++) {
            dfs(0, j, board);
            dfs(rows - 1, j, board);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};