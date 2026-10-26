class Solution {
public:
    int timer = 0;
    bool hasArticulation = false;
    void dfs(int i, int j,vector<vector<int>>& grid,vector<vector<bool>>& visited,vector<vector<int>>& tin,vector<vector<int>>& low,int pi,int pj,bool isRoot) {
        int m = grid.size(), n = grid[0].size();
        visited[i][j] = true;
        tin[i][j] = low[i][j] = timer++;

        int children = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x < 0 || x >= m || y < 0 || y >= n ||
                grid[x][y] == 0)
                continue;

            if (x == pi && y == pj)
                continue;

            if (visited[x][y]) {
                low[i][j] = min(low[i][j], tin[x][y]);
            } else {
                children++;

                dfs(x, y, grid, visited, tin, low,
                    i, j, false);

                low[i][j] = min(low[i][j], low[x][y]);

                if (!isRoot && low[x][y] >= tin[i][j])
                    hasArticulation = true;
            }
        }

        if (isRoot && children > 1)
            hasArticulation = true;
    }

    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int land = 0, sr = -1, sc = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    land++;
                    sr = i;
                    sc = j;
                }
            }
        }

        if (land <= 1)
            return land == 0 ? 0 : 1;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> tin(m, vector<int>(n, -1));
        vector<vector<int>> low(m, vector<int>(n, -1));

        dfs(sr, sc, grid, visited, tin, low, -1, -1, true);

        int components = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    components++;
                    if (components > 0)
                        return 0;
                }
            }
        }

        return hasArticulation ? 1 : 2;
    }
};