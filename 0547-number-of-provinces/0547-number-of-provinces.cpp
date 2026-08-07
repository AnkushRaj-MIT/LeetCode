class Solution {
public:
    void dfs(int u,vector<vector<int>>& isConnected,vector<bool> &vis){
        vis[u]=true;
        for(int v=0;v<isConnected.size();v++){
            if(isConnected[u][v]==1 && !vis[v]){
                dfs(v,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};