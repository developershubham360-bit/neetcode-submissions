class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        // Step 1: collect all rotten oranges
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == 2) {
                    q.push({r, c});
                }

                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        // No fresh oranges
        if (fresh == 0)
            return 0;

        vector<pair<int,int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        int minutes = 0;

        // Step 2: BFS
        while (!q.empty()) {

            int size = q.size();

            bool rottedThisMinute = false;

            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (auto &[dr, dc] : dirs) {

                    int nr = r + dr;
                    int nc = c + dc;

                    // invalid OR not fresh
                    if (nr < 0 || nc < 0 ||
                        nr >= rows || nc >= cols ||
                        grid[nr][nc] != 1)
                        continue;

                    // rot it
                    grid[nr][nc] = 2;

                    fresh--;

                    q.push({nr, nc});

                    rottedThisMinute = true;
                }
            }

            // only increment if spread happened
            if (rottedThisMinute)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};