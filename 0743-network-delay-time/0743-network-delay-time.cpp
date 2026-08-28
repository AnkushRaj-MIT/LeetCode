class Solution {
public:
    class Edge {
    public:
        int wt;
        int v;
        Edge(int weight, int dest) {
            v = dest;
            wt = weight;
        }
    };
    int dijkstra(int src, vector<vector<Edge>>& g, int V) {
        vector<int> dist(V + 1, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d != dist[u])
                continue;
            for (Edge e : g[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                    pq.push({dist[e.v], e.v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= V; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int V, int src) {
        vector<vector<Edge>> g(V + 1);
        for (auto& time : times) {
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            g[u].push_back(Edge(wt, v));
        }
        return dijkstra(src, g, V);
    }
};