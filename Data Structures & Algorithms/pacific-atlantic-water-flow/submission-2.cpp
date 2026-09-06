class Solution {
public:
    vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    void dfs(int r, int c, vector<vector<bool>> &ocean, vector<vector<int>> &heights) {
        ocean[r][c] = true;
        for (auto &[dr, dc]: directions) {
            int nr = r+dr, nc = c+dc;
            if (nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && ocean[nr][nc]==false && heights[nr][nc]>=heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
    void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &ocean, vector<vector<int>> & heights) {
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto &[dr, dc]: directions) {
                int nr = r+dr, nc = c+dc;
                if (nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && !ocean[nr][nc] && heights[nr][nc]>=heights[r][c]) {
                    q.push({nr, nc});
                } 
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        for (int c=0;c<COLS;c++) {
            dfs(0, c, pac, heights);
            dfs(ROWS-1, c, atl, heights);
        }
        for (int r=0;r<ROWS;r++) {
            dfs(r, 0, pac, heights);
            dfs(r, COLS-1, atl, heights);
        }
        vector<vector<int>> res;
        for (int i=0;i<ROWS;i++) {
            for (int j=0;j<COLS;j++) {
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
