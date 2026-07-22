class Solution {
public:
    void dfs(vector<bool> &vis, vector<vector<int>> adj, int src) {
        vis[src] = true;
        for (auto it: adj[src]) {
            if (!vis[it]) {
                dfs(vis, adj, it);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        for (int i=0;i<m;i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        cout<<"Yes";
        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i=0;i<n;i++) {
            if (!vis[i]) {
                dfs(vis, adj, i);
                cnt++;
            }
        }
        return cnt;
    }
};
