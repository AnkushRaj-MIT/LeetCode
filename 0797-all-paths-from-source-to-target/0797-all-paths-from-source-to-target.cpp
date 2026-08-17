class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int u,vector<vector<int>> &l){
        path.push_back(u);
        if(u==l.size()-1){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(int v:l[u]){
            dfs(v,l);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0,graph);
        return ans;
    }
};