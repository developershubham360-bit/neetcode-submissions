class Solution {
public:
    int Find(vector<int> &par, int i) {
        if (par[i]==i) return i;
        return Find(par, par[i]);
    }
    bool Union(vector<int> &par, vector<int> &size, int n1, int n2) {
        int p1 = Find(par, n1);
        int p2 = Find(par, n2);
        if (p1==p2) {
            return false;
        }
        if (size[p1]>size[p2]) {
            par[p2] = p1;
            size[p1] += size[p2];
        } else {
            par[p1] = p2;
            size[p2] += size[p1]; 
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> par(n+1), size(n+1,1);
        for (int i=0;i<=n;i++) {
            par[i] = i;
        }
        for (const auto& edge: edges) {
            if (!Union(par, size, edge[0], edge[1])) {
                return vector<int>{edge[0], edge[1]};
            }
        }
        return {};
    }
};