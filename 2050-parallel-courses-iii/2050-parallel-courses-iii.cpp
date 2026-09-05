class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n+1,0);
        vector<vector<int>> g(n+1);
        for(int i=0;i<relations.size();i++){
            int u=relations[i][0];
            int v=relations[i][1];
            g[u].push_back(v);
            indegree[v]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                pq.push({time[i-1],i});
            }
        }
        int ans=0;
        while(!pq.empty()){
            int t=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            ans=max(ans,t);
            for(int v: g[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    pq.push({t+time[v-1],v});
                }
            }
        }
        return ans;
    }
};