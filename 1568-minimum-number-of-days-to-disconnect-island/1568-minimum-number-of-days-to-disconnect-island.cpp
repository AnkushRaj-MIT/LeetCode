class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<int>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n||vis[i][j]||grid[i][j]==0) return;
        vis[i][j]=true;
        dfs(i+1,j,vis,grid);
        dfs(i-1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i,j-1,vis,grid);
    }
    int countIsland(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(countIsland(grid)!=1) return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(countIsland(grid)!=1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};