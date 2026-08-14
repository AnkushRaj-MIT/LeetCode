class Solution {
public:
    bool dfs(int u,int destination,vector<bool> &vis,vector<vector<int>> &l){
        vis[u]=true;
        if(u==destination) return true;
        for(int v:l[u]){
            if(!vis[v]){
                if(dfs(v,destination,vis,l)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> l(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            l[u].push_back(v);
            l[v].push_back(u);
        }
        vector<bool> vis(n,false);
        return dfs(source,destination,vis,l);
    }
};