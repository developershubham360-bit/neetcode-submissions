class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> ans;
        int n = prerequisites.size();
        for (int i=0;i<n;i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses, 0);
        for (int i=0;i<numCourses;i++) {
            for (auto it: graph[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it: graph[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        if(size(ans) == numCourses) return ans;              
        return {};
    }
};