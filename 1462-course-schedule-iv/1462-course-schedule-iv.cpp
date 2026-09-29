class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(numCourses);
        for(auto val : prerequisites) {
            int u = val[0];
            int v = val[1];
            g[u].push_back(v);
        }
        vector<vector<bool>> reach(numCourses, vector<bool>(numCourses, false));
        for(int i = 0; i < numCourses; i++) {
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : g[u]) {
                    if(!reach[i][v]) {
                        reach[i][v] = true;
                        q.push(v);
                    }
                }
            }
        }
        vector<bool> ans;
        for(auto val : queries) {
            int u = val[0];
            int v = val[1];
            ans.push_back(reach[u][v]);
        }
        return ans;
    }
};