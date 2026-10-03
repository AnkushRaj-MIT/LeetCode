class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int i,int j,int &count){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || visited[i][j] || grid[i][j]==0) return;
        visited[i][j]=true;
        count++;
        for(int row=0;row<m;row++){
            dfs(grid,visited,row,j,count);
        }
        for(int col=0;col<n;col++){
            dfs(grid,visited,i,col,count);
        }
    } 
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    int count=0;
                    dfs(grid,visited,i,j,count);
                    if(count>1) ans+=count;
                }
            }
        }
        return ans;
    }
};