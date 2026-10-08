class Solution {
public:
    int ans=INT_MAX;
    class Edge{
    public:
        int v;
        int wt;
        Edge(int dest,int w){
            v=dest;
            wt=w;
        }   
    };
    void dfs(int u,vector<vector<Edge>> &g,vector<bool> &vis){
        vis[u]=true;
        for(auto e:g[u]){
            ans=min(ans,e.wt);
            if(!vis[e.v]){
                dfs(e.v,g,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<Edge>> g(n+1);
        for(auto edge:roads){
            int u=edge[0];
            int v=edge[1];
            int dist=edge[2];
            g[u].push_back(Edge(v,dist));
            g[v].push_back(Edge(u,dist));
        }
        vector<bool> vis(n+1,false);
        dfs(1,g,vis);
        return ans;
    }
};