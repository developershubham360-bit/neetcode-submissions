class Solution {
public:
    int m, n;
    vector<vector<int>> matrix;
    vector<vector<int>> memo;

    int dfs(int i, int j) {
        // if already calculated, just return it
        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int best = 1;

        // check all 4 directions manually (simple, no fancy loops)
        // right
        if (j + 1 < n && matrix[i][j+1] > matrix[i][j]) {
            best = max(best, 1 + dfs(i, j+1));
        }
        // left
        if (j - 1 >= 0 && matrix[i][j-1] > matrix[i][j]) {
            best = max(best, 1 + dfs(i, j-1));
        }
        // down
        if (i + 1 < m && matrix[i+1][j] > matrix[i][j]) {
            best = max(best, 1 + dfs(i+1, j));
        }
        // up
        if (i - 1 >= 0 && matrix[i-1][j] > matrix[i][j]) {
            best = max(best, 1 + dfs(i-1, j));
        }

        memo[i][j] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& inputMatrix) {
        matrix = inputMatrix;
        m = matrix.size();
        n = matrix[0].size();

        // create memo table filled with 0
        memo.resize(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int pathLength = dfs(i, j);
                if (pathLength > ans) {
                    ans = pathLength;
                }
            }
        }

        return ans;
    }
};