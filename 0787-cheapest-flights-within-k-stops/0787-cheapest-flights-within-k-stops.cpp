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
    vector<int> bellman(int V, vector<vector<Edge>>& g, int src, int k) {
        vector<int> prices(V, INT_MAX);
        prices[src] = 0;
        // K stops = K + 1 flights
        for(int i = 0; i <= k; i++) {
            vector<int> temp = prices;
            for(int u = 0; u < V; u++) {
                if(prices[u] == INT_MAX)
                    continue;
                for(Edge e : g[u]) {
                    if(temp[e.v] > prices[u] + e.wt) {
                        temp[e.v] = prices[u] + e.wt;
                    }
                }
            }
            prices = temp;
        }
        return prices;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<Edge>> g(n);
        for(auto val : flights) {
            int u = val[0];
            int v = val[1];
            int wt = val[2];
            g[u].push_back(Edge(v, wt));
        }
        vector<int> prices = bellman(n, g, src, k);
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};