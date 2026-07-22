class Solution {
public:
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> &grid, int i, int j, int &count) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
        grid[i][j] = 0;
        count++;
        for (int it=0;it<4;it++) {
            dfs(grid, i+d[it][0], j+d[it][1], count);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    res = max(count, res);
                }
            }
        }
        return res;
    }
};
