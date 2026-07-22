class Solution {
public:
    string toposort(vector<unordered_set<int>> &adjList, vector<bool> &present) {
        queue<int> q;
        vector<int> indegree(26, 0);

        for (int u = 0; u < 26; u++) {
            for (int v : adjList[u]) {
                indegree[v]++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0)
                q.push(i);
        }
        string order;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            order += char(u + 'a');

            for (int v : adjList[u]) {
                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        int totalChars = 0;

        for (bool x : present)
            if (x) totalChars++;
        if (order.size() != totalChars)
            return "";
        return order;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<unordered_set<int>> adjList(26);
        vector<bool> present(26, false);
        for (string &word : words) {
            for (char c : word)
                present[c - 'a'] = true;    
        }
        for (int i=1;i<n;i++) {
            string a = words[i];
            string b = words[i-1];
            int len = min(a.length(), b.length());
            int j=0;
            while (j<len && a[j]==b[j]) j++;
            if (j==len && b.size()>a.size()) return "";
            if (j<len) {
                adjList[b[j]-'a'].insert(a[j]-'a');
            }
        }
        string ans = toposort(adjList, present);
        return ans;
    }
};
