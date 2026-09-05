class Solution {
public:
    vector<int> topologicalSort(int k,vector<vector<int>> &conditions){
        vector<int> indegree(k+1);
        vector<vector<int>> g(k+1);
        for(auto edge:conditions){
            int u=edge[0];
            int v=edge[1];
            g[u].push_back(v);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> priority;
        while(!q.empty()){
            int curr=q.front();
            priority.push_back(curr);
            q.pop();
            for(int v:g[curr]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        if(priority.size()!=k) return {};
        return priority;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int n=rowConditions.size();
        int m=colConditions.size();
        vector<vector<int>> ans(k,vector<int>(k,0));
        vector<int> rowPriority=topologicalSort(k,rowConditions);
        vector<int> colPriority=topologicalSort(k,colConditions);
        if(rowPriority.empty()||colPriority.empty()) return {};
        vector<int> colPos(k+1);
        vector<int> rowPos(k+1);
        for(int i=0;i<k;i++){
            rowPos[rowPriority[i]]=i;
            colPos[colPriority[i]]=i;
        }
        for(int num=1;num<=k;num++){
            ans[rowPos[num]][colPos[num]]=num;
        }
        return ans;
    }
};