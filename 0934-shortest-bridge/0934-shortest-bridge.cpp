class Solution {
public:
    vector<vector<bool>> vis;
    queue<pair<int,int>> q;
    void dfs(int i,int j,vector<vector<int>> &grid){
        int n=grid.size();
        if(i<0||j<0||i>=n||j>=n||vis[i][j]||!grid[i][j]) return;
        vis[i][j]=true;
        q.push({i,j});
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vis.assign(n,vector<bool> (n,false));
        bool found=false;
        for(int i=0;i<n && !found;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    found=true;
                    break;
                }
            }
        }
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto[i,j]=q.front();
                q.pop();
                int dx[]={1,-1,0,0};
                int dy[]={0,0,1,-1};
                for(int k=0;k<4;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x<0||y<0||x>=n||y>=n||vis[x][y]) continue;
                    if(grid[x][y]==1) return steps;
                    vis[x][y]=true;
                    q.push({x,y});
                }
            }
            steps++;
        }
        return -1;
    }
};