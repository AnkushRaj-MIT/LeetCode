class Graph {
public:
    class Edge{
    public:    
        int v;
        int wt;
        Edge(int dest,int weight){
            v=dest;
            wt=weight;
        }
    };
    int V;
    vector<vector<Edge>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        V=n;
        adj.resize(n);
        for(auto edge:edges){
            addEdge(edge);
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];;
        int wt=edge[2];
        adj[u].push_back(Edge(v,wt));
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(V,INT_MAX);
        dist[node1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        while(!pq.empty()){
            int u=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            for(auto e:adj[u]){
                if(dist[e.v]>dist[u]+e.wt){
                    dist[e.v]=dist[u]+e.wt;
                    pq.push({dist[e.v],e.v});
                }
            }
        }
        if(dist[node2]==INT_MAX) return -1;
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */