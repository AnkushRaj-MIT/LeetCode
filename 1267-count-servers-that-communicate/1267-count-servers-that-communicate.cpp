class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> Row(n);
        vector<int> Col(m);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                Row[i] += grid[i][j];
                Col[j] += grid[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && (Row[i]>1 || Col[j]>1)){
                    ans ++;
                }
            }
        }
        return ans;
    }
};
