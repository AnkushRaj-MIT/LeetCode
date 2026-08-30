class Solution {
public:
    class Edge{
    public:
        int v;int wt;
        Edge(int v,int wt){
            this->v=v;
            this->wt=wt;
        }
    };
    void dijkstra(int src,vector<vector<Edge>> &g,int V,vector<vector<int>> &dist){
        dist[src][src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(Edge e:g[u]){
                if(dist[src][e.v]>dist[src][u]+e.wt){
                    dist[src][e.v]=dist[src][u]+e.wt;
                    pq.push({dist[src][e.v],e.v});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<Edge>> g(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            g[u].push_back(Edge(v,weight));
            g[v].push_back(Edge(u,weight));
        }
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dijkstra(i,g,n,dist);
        }
        vector<int> cities(n,0);
        for(int i=0;i<n;i++){
            for(int wt:dist[i]){
                if(wt<=distanceThreshold) cities[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(cities[i]<=cities[ans]) ans=i;
        }
        return ans;
    }
};