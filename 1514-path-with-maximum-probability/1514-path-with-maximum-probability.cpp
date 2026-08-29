class Solution {
public:
    class Edge{
    public:
       int v;
       double wt;
       Edge(double weight,int dest){
           wt=weight;
           v=dest;
       }    
    };
    double dijkstra(int V,vector<vector<Edge>> &g,int st,int end){
        vector<double> prob(V,0.0);
        prob[st]=1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,st});
        while(!pq.empty()){
            int u=pq.top().second;
            double d=pq.top().first;
            pq.pop();
            for(Edge e:g[u]){
                if(prob[e.v]<prob[u]*e.wt){
                    prob[e.v]=prob[u]*e.wt;
                    pq.push({prob[e.v],e.v});
                }
            }
        }
        return prob[end];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int st, int end) {
        vector<vector<Edge>> g(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double weight=succProb[i];
            g[u].push_back(Edge(weight,v));
            g[v].push_back(Edge(weight,u));
        }
        return dijkstra(n,g,st,end);
    }
};