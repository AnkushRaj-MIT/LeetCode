class Solution {
public:
    int time = 0;
    bool hasArticulation = false;
    vector<vector<int>> dt, low;
    vector<vector<bool>> visited;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int i, int j, int pi, int pj, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited[i][j] = true;
        low[i][j] = dt[i][j] = ++time;
        int children = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || y < 0 || x >= m || y >= n ||grid[x][y] == 0) continue;
            if (x == pi && y == pj) continue;
            if (visited[x][y]) {
                low[i][j] = min(low[i][j], dt[x][y]);
            } else {
                dfs(x, y, i, j, grid);
                low[i][j] = min(low[i][j], low[x][y]);
                if (pi != -1 && low[x][y] >= dt[i][j]) hasArticulation = true;
                children++;
            }
        }
        if (pi == -1 && children > 1)
            hasArticulation = true;
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int land = 0, si = -1, sj = -1;
        visited.assign(m, vector<bool>(n, false));
        dt.assign(m, vector<int>(n, 0));
        low.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    land++;
                    si = i;
                    sj = j;
                }
            }
        }
        if (land <= 1) return land;
        dfs(si, sj, -1, -1, grid);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j])return 0;
            }
        }
        return hasArticulation ? 1 : 2;
    }
};
