class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int V= n;
        vector<vector<int>> adj(V);
        for(auto &it: relations){
            int u= it[0]-1;
            int v= it[1]-1;
            adj[u].push_back(v);
        }
        vector<int> inDegree(V,0);
        for(int i=0;i<V;i++){
            for(int &v: adj[i]){
                inDegree[v]++;
            }
        }
        queue<int> q;
        int ans=0;
        vector<int> finish(n, 0);
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
                finish[i]= time[i];
            }
        }
        while(!q.empty()){
            int u= q.front();
            q.pop();
            ans= max(ans, finish[u]);
            for(int &v: adj[u]){
                finish[v]= max(finish[v],finish[u]+time[v]);
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }
        return ans;
    }
};