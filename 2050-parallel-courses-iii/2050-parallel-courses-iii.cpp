class Solution {
public:
    int ans=0;
    void topologicalSort(int n,vector<vector<int>>& relations, vector<int>& time){
        vector<vector<int>> g(n+1);
        vector<int> indegree(n+1,0);
        for(auto edge:relations){
            int u=edge[0];
            int v=edge[1];
            g[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> minTime(n+1,0);
        while(!q.empty()){
            int u=q.front();
            int finishTime=minTime[u]+time[u-1];
            ans=max(ans,finishTime);
            q.pop();
            for(int v:g[u]){
                minTime[v] = max(minTime[v], finishTime);
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        topologicalSort(n,relations,time);
        return ans;
    }
};