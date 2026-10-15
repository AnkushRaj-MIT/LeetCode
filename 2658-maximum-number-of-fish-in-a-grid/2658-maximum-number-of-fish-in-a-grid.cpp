class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> & grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n||!grid[i][j]) return 0;
        int count=0;
        count+=grid[i][j];
        grid[i][j]=0;
        count+=dfs(i+1,j,grid);
        count+=dfs(i-1,j,grid);
        count+=dfs(i,j+1,grid);
        count+=dfs(i,j-1,grid);
        return count;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};