class Solution {
public:
    void dfs(int num,int &count,int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis){
        int n=grid.size();
        if(i<0||j<0||i>=n||j>=n||vis[i][j]||grid[i][j]==0) return ;
        count++;
        vis[i][j]=true;
        grid[i][j]=num;
        dfs(num,count,i+1,j,grid,vis);
        dfs(num,count,i-1,j,grid,vis);
        dfs(num,count,i,j+1,grid,vis);
        dfs(num,count,i,j-1,grid,vis);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> vis (n,vector<bool>(n,false));
        int num=2;
        int ans=0;
        vector<int> area(n*n+2);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    int count=0;
                    dfs(num,count,i,j,grid,vis);
                    area[num]=count;
                    ans=max(ans,count);
                    num++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                unordered_set<int> s;
                if(grid[i][j]==0){
                    int sum=1;
                    if(i+1<n && grid[i+1][j]!=0 && s.find(grid[i+1][j])==s.end()){
                        sum+=area[grid[i+1][j]];
                        s.insert(grid[i+1][j]);
                    }
                    if(i-1>=0 && grid[i-1][j]!=0 && s.find(grid[i-1][j])==s.end()){
                        sum+=area[grid[i-1][j]];
                        s.insert(grid[i-1][j]);
                    }
                    if(j+1<n && grid[i][j+1]!=0 && s.find(grid[i][j+1])==s.end()){
                        sum+=area[grid[i][j+1]];
                        s.insert(grid[i][j+1]);
                    }
                    if(j-1>=0 && grid[i][j-1]!=0 && s.find(grid[i][j-1])==s.end()){
                        sum+=area[grid[i][j-1]];
                        s.insert(grid[i][j-1]);
                    }
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};