class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> g(n);
        vector<int> degree(n, 0);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        // Add all leaf nodes
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        int remaining = n;
        while(remaining > 2){
            int size = q.size();
            remaining -= size;
            for(int i = 0; i < size; i++){
                int leaf = q.front();
                q.pop();
                for(int v : g[leaf]){
                    degree[v]--;
                    if(degree[v] == 1) q.push(v);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};