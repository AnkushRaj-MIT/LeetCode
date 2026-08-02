class Solution {
public:
    class Graph{
        int V;
        list<int> *l;
    public:
        Graph(int V){
            this->V=V;
            l=new list<int>[V+1];
        }
        void addEdge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        bool dfs(int u,int parent,vector<bool> &vis){
            vis[u]=true;
            for(int v:l[u]){
                if(!vis[v]){
                    if(dfs(v,u,vis)) return true;
                }
                else if(v!=parent) return true;
            }
            return false;
        }
        bool hasCycle(){
            vector<bool> vis(V+1,false);
            for(int i=1;i<V;i++){
                if(!vis[i]){
                    if(dfs(i,-1,vis)) return true;
                }
            }
            return false;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Graph g(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            g.addEdge(u,v);
            if(g.hasCycle()) return edge;
        }
        return {};
    }
};