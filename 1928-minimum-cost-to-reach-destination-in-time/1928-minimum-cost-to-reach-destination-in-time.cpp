class Solution {
public:
    class Edge {
    public:
        int v, time, fees;
        Edge(int dest, int t, int f) {
            v = dest;
            time = t;
            fees = f;
        }
    };
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<Edge>> g(n);
        for (auto e : edges) {
            int u = e[0], v = e[1], t = e[2];
            g[u].push_back(Edge(v, t, passingFees[v]));
            g[v].push_back(Edge(u, t, passingFees[u]));
        }
        vector<int> minTime(n, INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        minTime[0] = 0;
        pq.push({passingFees[0],0,0});//{cost,u,time}
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0];
            int u = curr[1];
            int time = curr[2];
            if(u==n-1) return cost;
            for (Edge e : g[u]) {
                int newCost = cost + e.fees;
                int newTime = time + e.time;
                if (newTime <= maxTime && newTime < minTime[e.v]) {
                    minTime[e.v] = newTime;
                    pq.push({newCost, e.v , newTime});
                }
            }
        }
        return -1;
    }
};