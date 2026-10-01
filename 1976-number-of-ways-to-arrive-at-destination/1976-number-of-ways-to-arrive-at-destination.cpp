class Solution {
public:
    class Edge {
    public:
        int v;
        int wt;
        Edge(int dest, int weight) {
            v = dest;
            wt = weight;
        }
    };
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<Edge>> g(n);
        for(auto val : roads) {
            int u = val[0];
            int v = val[1];
            int wt = val[2];
            g[u].push_back(Edge(v, wt));
            g[v].push_back(Edge(u, wt));
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;
        while(!pq.empty()) {
            auto val = pq.top();
            pq.pop();
            long long d = val.first;
            int src = val.second;
            if(d > dist[src]) continue;
            for(auto edge : g[src]) {
                int v = edge.v;
                int wt = edge.wt;
                long long newDist = d + wt;
                if(newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[src];
                    pq.push({newDist, v});
                }
                else if(newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[src]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};