class Solution {
public:  
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> rev(n);
        vector<int> outdegree(n);
        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
            for(int node:graph[i]){
                rev[node].push_back(i);
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int v:rev[u]){
                outdegree[v]--;
                if(outdegree[v]==0) q.push(v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};