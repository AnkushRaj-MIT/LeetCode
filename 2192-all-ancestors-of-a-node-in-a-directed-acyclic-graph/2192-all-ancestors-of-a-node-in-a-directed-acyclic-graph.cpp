class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<vector<bool>> isAncestor(n, vector<bool>(n, false));
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int v:adj[curr]) {
                isAncestor[v][curr] = true;
                for (int i = 0; i < n; i++) {
                    if (isAncestor[curr][i]) {
                        isAncestor[v][i] = true;
                    }
                }
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isAncestor[i][j]) {
                    ans[i].push_back(j);
                }
            }
        }
        return ans;
    }
};
