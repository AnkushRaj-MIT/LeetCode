class Solution {
public:
    void dfs(int u,vector<vector<int>> &l,vector<bool> &vis,int &count){
        vis[u]=true;
        count++;
        for(int v:l[u]){
            if(!vis[v]){
                dfs(v,l,vis,count);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        int count=0;
        dfs(0,rooms,vis,count);
        return (count==n);
    }
};