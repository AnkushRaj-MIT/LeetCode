class Solution {
public:
    int dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<int>> &grid,int m,int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0||vis[i][j]==true) return 0;
        vis[i][j]=true;
        int v1=dfs(i+1,j,vis,grid,m,n);
        int v2=dfs(i,j+1,vis,grid,m,n);
        int v3=dfs(i-1,j,vis,grid,m,n);
        int v4=dfs(i,j-1,vis,grid,m,n);
        return 1+v1+v2+v3+v4;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxArea=0;
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false && grid[i][j]==1){
                    int area=dfs(i,j,vis,grid,m,n);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};