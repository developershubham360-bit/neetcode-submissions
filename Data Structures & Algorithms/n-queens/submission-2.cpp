class Solution {
public:

    vector<vector<string>> ans;

    vector<string> board;

    vector<int> col;
    vector<int> diag1;
    vector<int> diag2;

    void backtrack(int row, int n) {

        // Base case
        if(row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column
        for(int c = 0; c < n; c++) {

            // Check if safe
            if(col[c] ||
               diag1[row - c + n - 1] ||
               diag2[row + c])
                continue;

            // Place queen
            board[row][c] = 'Q';

            col[c] = 1;
            diag1[row - c + n - 1] = 1;
            diag2[row + c] = 1;

            // Explore next row
            backtrack(row + 1, n);

            // Undo
            board[row][c] = '.';

            col[c] = 0;
            diag1[row - c + n - 1] = 0;
            diag2[row + c] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        board = vector<string>(n, string(n, '.'));

        col = vector<int>(n, 0);

        diag1 = vector<int>(2*n - 1, 0);
        diag2 = vector<int>(2*n - 1, 0);

        backtrack(0, n);

        return ans;
    }
};