class Solution {
public:
    bool dfs(int u,vector<vector<int>> &l,vector<bool> &vis,vector<bool> &pathVis){
        vis[u]=true;
        pathVis[u]=true;
        for(int v:l[u]){
            if(!vis[v]){
                if(dfs(v,l,vis,pathVis)) return true;
            }else if(pathVis[v]){
                return true;
            }
        }
        pathVis[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> pathVis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)) return false;
            }
        }
        return true;
    }
};