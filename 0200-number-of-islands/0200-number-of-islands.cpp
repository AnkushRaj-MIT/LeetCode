class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<char>> &grid,int m,int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0'||vis[i][j]==true) return;
        vis[i][j]=true;
        dfs(i+1,j,vis,grid,m,n);
        dfs(i,j+1,vis,grid,m,n);
        dfs(i-1,j,vis,grid,m,n);
        dfs(i,j-1,vis,grid,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false && grid[i][j]=='1'){
                    dfs(i,j,vis,grid,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};