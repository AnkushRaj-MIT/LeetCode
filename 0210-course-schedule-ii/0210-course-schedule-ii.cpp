class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        stack<int> st;
        vector<int> vis(numCourses);
        vector<int> path(numCourses);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(adj,i,vis,st,path)==false) return {};
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();

        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
    bool dfs(vector<vector<int>> &adj, int node, vector<int> & vis,stack<int> &st, vector<int>& path){
        vis[node]=1;
        path[node]=1;
        for(auto it: adj[node]){
            if(path[it]==1) return false;
            if(!vis[it]){
                dfs(adj,it,vis,st,path);
            }
        }
        path[node]=0;
        st.push(node);
        return true;
    }

};       