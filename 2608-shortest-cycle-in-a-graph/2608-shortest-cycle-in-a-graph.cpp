class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            vector<int> parent(n,-1);
            vector<int> dist(n,-1);//distance from starting node(if dist==-1 then node is not visited ,else it is visited)
            queue<int> q;
            q.push(i);
            dist[i]=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:adj[u]){
                    if(dist[v]==-1){
                        q.push(v);
                        dist[v]=dist[u]+1;
                        parent[v]=u;
                    }
                    else if(parent[u]!=v){
                        ans=min(ans,dist[u]+dist[v]+1);
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};