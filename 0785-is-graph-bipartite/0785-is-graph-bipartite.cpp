class Solution {
public:
    bool dfs(int u,vector<vector<int>>& graph,vector<int> &color){
        for(int v:graph[u]){
            if(color[v]==-1){
                color[v]=1-color[u];
                if(dfs(v,graph,color)) return true;
            }
            else if(color[u]==color[v]) return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        //-1->not visited,0->group1,1->group 2
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(dfs(i,graph,color)) return false;
            }
        }
        return true;
    }
};