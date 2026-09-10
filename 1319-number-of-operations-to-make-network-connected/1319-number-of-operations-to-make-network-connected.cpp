class Solution {
public:
    void dfs(int u,vector<vector<int>> &adj,vector<bool> &vis){
        vis[u]=true;
        for(int v:adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<(n-1)) return -1;//to connect n components we need n-1 cables
        vector<vector<int>> adj(n);
        for(auto val:connections){
            int u=val[0];
            int v=val[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans-1;
    }
};