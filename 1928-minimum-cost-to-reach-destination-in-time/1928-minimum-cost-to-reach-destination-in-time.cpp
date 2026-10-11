class Solution {
public:
    class Edge{
    public:
       int v;
       int time;
       int fees;
       Edge(int dst,int t,int f){
        v=dst;
        time=t;
        fees=f;
       }    
    };
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
      int n=passingFees.size();
      vector<vector<Edge>> g(n);
      for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int t=edge[2];
        g[u].push_back(Edge(v,t,passingFees[v]));
        g[v].push_back(Edge(u,t,passingFees[u]));
      }  
      vector<vector<int>> dist(n,vector<int> (maxTime+1,INT_MAX));   //dist[city][time]
      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
      dist[0][0]=passingFees[0];
      pq.push({passingFees[0],0,0});//{cost,city,time}
      while(!pq.empty()){
        int cost=pq.top()[0];
        int u=pq.top()[1];
        int t=pq.top()[2];
        pq.pop();
        if(u==n-1) return cost;
        for(Edge e:g[u]){
            int newTime=t+e.time;
            int newCost=cost+e.fees;
            if(newTime<=maxTime && newCost< dist[e.v][newTime]){
                dist[e.v][newTime]=newCost;
                pq.push({newCost,e.v,newTime});
            }
        }
      }
      return -1;
    }
};