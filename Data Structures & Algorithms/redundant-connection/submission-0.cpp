class Solution {
public:

    bool dfs(int src,
             int target,
             vector<vector<int>>& adj,
             vector<bool>& vis) {

        if (src == target)
            return true;

        vis[src] = true;

        for (int nei : adj[src]) {

            if (!vis[nei]) {

                if (dfs(nei, target, adj, vis))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];

            vector<bool> vis(n + 1, false);

            // if path already exists, edge is redundant
            if (dfs(u, v, adj, vis))
                return e;

            // otherwise add edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};