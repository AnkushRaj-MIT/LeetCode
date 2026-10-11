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
    int findCheapestPrice(int n, vector<vector<int>>& flights,int src, int dst, int k) {
        vector<vector<Edge>> g(n);
        for (auto val : flights) {
            int u = val[0];
            int v = val[1];
            int wt = val[2];
            g[u].push_back(Edge(v, wt));
        }
        vector<int> prices(n, INT_MAX);
        queue<vector<int>> q;
        prices[src] = 0;
        q.push({src, 0, -1});//src,price,stops
        while (!q.empty()) {
            int u = q.front()[0];
            int price = q.front()[1];
            int stops = q.front()[2];
            q.pop();
            if (stops >= k) {
                continue;
            }
            for (Edge e : g[u]) {
                if (price + e.wt < prices[e.v] && stops + 1 <= k) {
                    prices[e.v] = price + e.wt;
                    q.push({e.v, prices[e.v], stops + 1});
                }
            }
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};