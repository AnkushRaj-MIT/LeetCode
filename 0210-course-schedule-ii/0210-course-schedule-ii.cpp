class Solution {
public:
    bool isCycleDFS(int u,vector<bool> &vis,vector<bool> &pathVis,vector<vector<int>>& prerequisites){
        vis[u]=true;
        pathVis[u]=true;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int des=prerequisites[i][0];
            int src=prerequisites[i][1];
            if(u==src){
                if(!vis[des]){
                    if(isCycleDFS(des,vis,pathVis,prerequisites)) return true;
                } 
                else if(pathVis[des]) return true;
            }
        }
        pathVis[u]=false;
        return false;        
    }
    void topologicalSort(int u,stack<int> &s,vector<bool> &vis,vector<vector<int>> &prerequisites){
        vis[u]=true;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int des=prerequisites[i][0];
            int src=prerequisites[i][1];
            if(u==src){
                if(!vis[des]){
                    topologicalSort(des,s,vis,prerequisites);
                } 
            }
        }
        s.push(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> pathVis(numCourses,false);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,pathVis,prerequisites)) return ans;
            }
        }
        vis.assign(numCourses,false);
        stack<int> s;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                topologicalSort(i,s,vis,prerequisites);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};