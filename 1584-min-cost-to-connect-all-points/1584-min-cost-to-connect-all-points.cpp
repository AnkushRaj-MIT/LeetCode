class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({cost,j});
                adj[j].push_back({cost,i});
            }
        }
        vector<bool> vis(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
            auto [cost,u]=pq.top();
            pq.pop();
            if(!vis[u]){
                vis[u]=true;
                ans+=cost;
                for(auto val:adj[u]){
                    int v=val.second;
                    int wt=val.first;
                    if(!vis[v]){
                        pq.push({wt,v});
                    }
                }
            }
        }
        return ans;
    }
};