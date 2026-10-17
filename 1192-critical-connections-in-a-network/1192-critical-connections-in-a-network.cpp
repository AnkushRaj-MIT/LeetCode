class Solution {
public:
    vector<vector<int>> adj;
    vector<int> dt,low;
    vector<vector<int>> bridges;
    int time=0;
    void dfs(int u,vector<bool> &vis,int parU){
        vis[u]=true;
        dt[u]=low[u]=++time;
        for(int v:adj[u]){
            if(!vis[v]){
                dfs(v,vis,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>dt[u]) bridges.push_back({u,v});
            }
            else if(v!=parU){
                low[u]=min(low[u],low[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        dt.assign(n,0);
        low.resize(n);
        for(auto edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        dfs(0,vis,-1);
        return bridges;
    }
};