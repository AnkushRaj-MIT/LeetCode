class Solution {
public:
    
    void dfs(int row, int col , vector<vector<int>>& grid, int n, int m, int &result ){
        if(row < 0 || row >= n || col <0 || col >= m ) return ;

        if(grid[row][col] == 1){
            result++;
            grid[row][col] = 0;
        

        dfs(row+1,col,grid,n,m,result);
        dfs(row-1,col,grid,n,m,result);
        dfs(row,col+1,grid,n,m,result);
        dfs(row,col-1,grid,n,m,result);
        }

        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int area = 0;

        for(int i =0; i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    int result = 0;
                    dfs(i,j,grid,n,m,result);
                    area = max(area,result);
                }
            }
        }

        return area;
    }
};