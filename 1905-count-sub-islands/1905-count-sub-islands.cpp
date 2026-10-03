class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        if(i<0 || i>=m || j<0|| j>=n || grid2[i][j]==0) return true;
        grid2[i][j]=0;
        bool ans=true;
        if(grid1[i][j]==0) ans=false;
        ans=dfs(grid1,grid2,i+1,j) && ans;
        ans=dfs(grid1,grid2,i-1,j) && ans;
        ans=dfs(grid1,grid2,i,j+1) && ans;
        ans=dfs(grid1,grid2,i,j-1) && ans;
        return ans;
    }
    int m,n;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid1.size();
        n=grid1[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1)
                    if(dfs(grid1,grid2,i,j)) count++;
            }
        }
        return count;
    }
};